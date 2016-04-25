//Tool.cpp

#include "Tool.h"
#include "ColorData.h"
#include "PixelBuffer.h"


#include <iostream>
#include <cmath>

//Default constructer 
Tool::Tool()
{
  m_colors = new ColorData;
}

Tool::~Tool()
{
  delete [] m_mask;
  delete m_colors;
}

//Tool recives the color from the BrushworkApp when the mouse is pressed
void Tool::setColor(float red, float green, float blue)
{
  m_colors->setRed(red);
  m_colors->setGreen(green);
  m_colors->setBlue(blue);
}
//draw sets the pixels covered by the mask blending the colors when needed
void Tool::draw(int x, int y, PixelBuffer *base)
{
	
  for(int i = 0; i<m_height; i++)
  {
    for(int j = 0; j < m_width; j++)
      {
		int height = y+i-(m_height/2);
		int width = x+j-(m_width/2);
		if (width>=0&&width<base->getWidth()&&height>=0&&height<base->getHeight())
			base->setPixel((width),(height),((*m_colors)*m_mask[i*m_width+j])+(base->getPixel(width,height)*(1.0-m_mask[i*m_width+j]))); 
      
      }
  }

}
//for BoxBrush
void Tool::drawEdge(int x, int y, PixelBuffer *base){} 
//for Stamp
void Tool::draw(int x, int y, PixelBuffer *base, PixelBuffer* stampImage){}
