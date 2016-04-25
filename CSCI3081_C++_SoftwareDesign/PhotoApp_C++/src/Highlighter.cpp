//Highlighter.cpp

#include "Highlighter.h"
#include "Tool.h"

Highlighter::Highlighter()
{
//Same as the calligraphy pen except with all values being .4
       m_width = 5;
       m_height = 15;
       m_mask = new float[m_height*m_width];
       for(int i = 0; i<m_height; i++)
    	 {
    	   for(int j = 0; j < m_width; j++)
    	     {
    	       m_mask[i*m_width+j] = .4;
    	     }
    	 }
}
Highlighter::~Highlighter(){}
