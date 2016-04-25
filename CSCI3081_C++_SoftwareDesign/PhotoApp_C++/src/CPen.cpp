//CPen.cpp

#include "CPen.h"
#include "Tool.h"

CPen::CPen()
{
	m_width = 5;
    m_height = 15;
    m_mask = new float[m_height*m_width];
    //because the mask is the size of the mask all indexes should be 1.0
    for(int i = 0; i<m_height; i++)
    {
      for(int j = 0; j < m_width; j++)
      {
          m_mask[i*m_width+j] = 1;
      }
    }
}
CPen::~CPen(){}
