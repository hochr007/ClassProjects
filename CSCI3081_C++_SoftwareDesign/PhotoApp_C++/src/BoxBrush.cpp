//BoxBrush.cpp

#include "BoxBrush.h"
#include "Tool.h"
#include <iostream>

BoxBrush::BoxBrush()
{
//Creates a brush in the shape of a empty box which gives a 3D effect when the brush is dragged
      m_width = 51;
      m_height = 51;
      m_mask = new float[m_height*m_width];   
      for(int i = 0; i<m_height; i++) //Places 1s in the outside indexes of the array
    	{
    	  for(int j = 0; j < m_width; j++)
    	    {
	      if(i==0 ||j==0 ||i==(m_width-1) || j == (m_height-1))
			m_mask[i*m_width+j] = 1;
	      else
			m_mask[i*m_width+j] = 0;
    	    }
    	}
}
BoxBrush::~BoxBrush(){}
// edges for cont drawing
void BoxBrush::drawEdge(int x, int y, PixelBuffer *base)
{
	
	base->setPixel((x-m_width/2),(y-m_height/2),((*m_colors)));
	base->setPixel((x-m_width/2),(y+m_height/2),((*m_colors)));
	base->setPixel((x+m_width/2),(y-m_height/2),((*m_colors)));
	base->setPixel((x+m_width/2),(y+m_height/2),((*m_colors)));

  

}
