//JpegApp.h

#ifndef JPEGAPP_H
#define JPEGAPP_H

class PixelBuffer;
class ColorData;

class JpegApp
{
 public:
  	JpegApp();
  	virtual ~JpegApp();
  	
	ColorData* loadImage(char* file_name);
	void saveImage(char* file_name, PixelBuffer* CD_buffer, int width, int height, int numChannels);
  	int getImageWidth();
  	int getImageHeight();
	
 private:
  	
	int m_width;
	int m_height;
	int m_numChannels;
	
};
#endif
