//SprayCan.cpp

#include "SprayCan.h"
#include "Tool.h"

#include <cmath>

SprayCan::SprayCan()
{
	m_width = 41;
	m_height = 41;
	m_mask = new float[m_width * m_height];
	
	for(int i=0; i<m_height; i++){
		
		for(int j= 0; j<m_width; j++){
	
			int x_dist, y_dist;
			float dist;
			
			y_dist = (m_height/2) - i; //y distance of pixel from the center pixel of mask
			x_dist = (m_width/2) - j; //x distance of pixel from the center pixel of mask
			dist = sqrt((x_dist* x_dist) +(y_dist * y_dist)); //Pythagorean's Theorem
			
			if(dist >= 20.0) //any distance over 20 is fully transparent
				m_mask[i*m_width+j] = 0;
			
			else
				m_mask[i*m_width+j] =((20.0-dist)/20.0)*0.6; //0.8 is minimum transparency, take fraction of that
			//base on how far away it is from the center.
		}
	}
}
SprayCan::~SprayCan(){}

void SprayCan::draw(int x, int y, PixelBuffer *base)
{

  for(int i = 0; i<m_height; i++)
  {
    for(int j = 0; j < m_width; j++)
      {
		int height = y+i-(m_height/2);
		int width = x+j-(m_width/2);
		if (width>=0 && width<base->getWidth() && height>=0 && height<base->getHeight())
			base->setPixel((width),(height),((*m_colors)*powf(m_mask[i*m_width+j],3))+(base->getPixel(width,height)*(1.0-powf(m_mask[i*m_width+j],3)))); 
      
      }
  }

}
