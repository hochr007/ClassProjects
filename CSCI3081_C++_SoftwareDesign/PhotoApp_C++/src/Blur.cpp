//Blur.cpp


#include "Blur.h"
#include "Tool.h"
#include "ColorData.h"
#include "PixelBuffer.h"
#include <cmath>



Blur::Blur()
{
    m_width = 41;
    m_height = 41;
    m_mask = new float[m_height*m_width];
    
    
    //pen implementation for compiling
    
    for(int i = 0; i<m_height; i++)
	{
	  for(int j = 0; j < m_width; j++) 
	    {
			int x_dist, y_dist;
			float dist;
			
			y_dist = (m_height/2) - i; //y distance of pixel from the center pixel of mask
			x_dist = (m_width/2) - j; //x distance of pixel from the center pixel of mask
			dist = sqrt((x_dist* x_dist) +(y_dist * y_dist)); //Pythagorean's Theorem
			
			if(dist >= 20.0) //any distance over 20 is fully transparent
				m_mask[i*m_width+j] = 0;
			
			else
				m_mask[i*m_width+j] =((20.0-dist)/20.0);
			}
	}
	
	
	
	

}

void Blur::draw(int x, int y, PixelBuffer* base){
	
	PixelBuffer * copy = new PixelBuffer(base->getWidth(),base->getHeight(),base->getBackgroundColor());
	copy->copyPixelBuffer(copy, base);
	for(int i=0; i<m_height; i++){
		for(int j=0; j<m_width; j++){
			ColorData total(0,0,0);
			float counter=0;
			
			for(int p=0; p<41 ; p++){
				for(int w=0; w<41 ; w++){
					float dist;
					
					dist = m_mask[w*m_width+p];
					
					if(((x-20+j)-20)+w >=0 && ((x-20+j)-20)+w < base->getWidth() && ((y-20+i)-20)+p >=0 && ((y-20+i)-20)+p < base->getHeight()){
						

						if(dist <= 20){ 
							total = total + copy->getPixel(((x-20+j)-20)+w,((y-20+i)-20)+p);
							counter++;

						}
						
					}
				}
			}
			int height = y+i-(m_height/2);
			int width = x+j-(m_width/2);
			total = total* (1./counter);
			total.clampedColor();
			total = total*m_mask[i*m_width+j] + base->getPixel(width,height)*(1.0-m_mask[i*m_width+j]);
			total.clampedColor();
			
			
			if (width>=0 && width<base->getWidth() && height>=0 && height<base->getHeight())
				base->setPixel(width, height, total); 

      
		}
	}
	delete copy;

}
Blur::~Blur(){
	
}
