//JpegApp.cpp

#include "JpegApp.h"
#include "ColorData.h"
#include "PixelBuffer.h"

#include "jpeglib.h"
#include "jerror.h"

#include <stdio.h>
#include <stdlib.h> 

#include <iostream>
#include <cstring>
#include <string>

using std::cout;
using std::endl;

JpegApp::JpegApp()
{
}

JpegApp::~JpegApp()
{
}

//Getter Methods


int JpegApp::getImageWidth(){
	return m_width;
}
int JpegApp::getImageHeight(){
	return m_height;
}
//Image Loading 1

ColorData* JpegApp::loadImage(char* file_name){
	
	unsigned char * rowptr;    // pointer to an array
  	unsigned char * jdata;        // data for the image
  	struct jpeg_decompress_struct info; //for our jpeg info
  	struct jpeg_error_mgr err;          //the error handler
	
	FILE* file = fopen((char*)file_name, "rb");  //open the file
	//error handler if the jpeg file doesn't load
  	if(!file) {
     		fprintf(stderr, "Error reading JPEG file %s!", file_name);
     		return 0;
  	}
		
  	info.err = jpeg_std_error(&err);     
  	jpeg_create_decompress(&info);   //fills info structure
	
	jpeg_stdio_src(&info, file);    
  	jpeg_read_header(&info, TRUE);   // read jpeg file header
	
  	jpeg_start_decompress(&info);    // decompress the file

	//set width and height
  	m_width = info.output_width;
  	m_height = info.output_height;
  	m_numChannels = info.num_components;

	

  	//int type = GL_RGBA;
  	unsigned long data_size = m_width * m_height * m_numChannels;
	
	// read RGBA scanlines one at a time & put bytes in jdata[] array. 
	jdata = (unsigned char *)malloc(data_size);
	
  	while (info.output_scanline < m_height) {

    		// Enable jpeg_read_scanlines() to fill our jdata array
    		rowptr = jdata + m_numChannels * info.output_width * info.output_scanline; 	
		jpeg_read_scanlines(&info, &rowptr, 1);
  	}

	jpeg_finish_decompress(&info);   //finish decompressing

	fclose(file);                    //close the file
	
	//transform to a ColorData array
	ColorData* CD_buf = new ColorData[m_width * m_height];
	
	int j=0;	
	for (int i=0;i<(m_width * m_height);i++){	

		CD_buf[i].setRed(((float)jdata[j])/255.0);
		CD_buf[i].setGreen(((float)jdata[j+1])/255.0);
		CD_buf[i].setBlue(((float)jdata[j+2])/255.0);
		if (m_numChannels==4)
			CD_buf[i].setAlpha(((float)jdata[j+3])/255.0);
		j=j+ m_numChannels;
	}

	
	free(jdata); 			//free the data array

	//return pointer to ColorData array
	return CD_buf;
}


//Image Saving

void JpegApp::saveImage(char* file_name, PixelBuffer* displayBuffer, int width, int height, int numChannels){

	struct jpeg_compress_struct info; //for our jpeg info
  	struct jpeg_error_mgr err;          //the error handler
	unsigned char * image_buffer;		    // Points to large array of R,G,B-order data 
	int row_stride;
	JSAMPROW row_ptr[1];
	
	FILE* file = fopen((char*)file_name, "rb");  //open the file
	//error handler if the jpeg file doesn't load
  	if(!file) {
     		fprintf(stderr, "Error reading JPEG file %s!", file_name);
  	}

	info.err = jpeg_std_error(&err);
	jpeg_create_compress(&info);
	jpeg_stdio_dest(&info,file);

	//set width and height

	info.image_width = width; 	/* image width and height, in pixels */
  	info.image_height = height;
  	info.input_components =numChannels;		/* # of color components per pixel */
  	info.in_color_space = JCS_RGB; 	/* colorspace of input image */
  
  	jpeg_set_defaults(&info);
	jpeg_set_quality(&info,50,TRUE);	
		
	//fill in image_buffer
	image_buffer = (unsigned char *)malloc(width * height * numChannels);
		
	int j=0;	
	//for (int i=0;i<(width * height);i++){	
	for (int y=0;y<height;y++){
		for(int x=0;x<width;x++){
			
			unsigned int pxIndex =((y*width)+x)*info.input_components;
			
			y=height-y-1;
			image_buffer[pxIndex] = displayBuffer->getPixel(x,y).getRed()*255;
			image_buffer[pxIndex+1] = displayBuffer->getPixel(x,y).getGreen()*255;
			image_buffer[pxIndex+2] = displayBuffer->getPixel(x,y).getBlue()*255;
		}
	}	


	jpeg_start_compress(&info, TRUE);

	row_stride = width * numChannels;	/* JSAMPLEs per row in image_buffer */
	
	while (info.next_scanline < info.image_height) {
   
    		row_ptr[0] = &image_buffer[info.next_scanline * row_stride];

    		(void) jpeg_write_scanlines(&info, row_ptr, 1);

  	}

	
	jpeg_finish_compress(&info);
	
	/* After finish_compress, we can close the output file. */
	
  	jpeg_destroy_compress(&info);
	fclose(file);
	free(image_buffer);
}

