//Pen.cpp

#include "Pen.h"
#include "Tool.h"

Pen::Pen()
{
	m_width = 3;
    m_height = 3;
    m_mask = new float[m_height*m_width];
    for(int i = 0; i<m_height; i++)
	{
	  for(int j = 0; j < m_width; j++) //for pen in 3X3 array the circle can be easly represented as a cross through the 1s
	    {
	      if(i==1 ||j==1)
	       	m_mask[i*m_width+j] = 1;
	       else
	      	m_mask[i*m_width+j] = 0;
	    }
	}
}
Pen::~Pen(){}
