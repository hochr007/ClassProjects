//Eraser.cpp

#include "Eraser.h"
#include "Tool.h"

#include <iostream>

//The constructor of Eraser creates the circle-shaped mask of the Eraser with diameter 21 pixels by setting all points that lie outside the circle in a 21x21 square to 0 and all others to 1 in the array mask
Eraser::Eraser()
{
  m_width = 21; //Diameter of Eraser
  m_height = 21;
  m_mask = new float[m_height*m_width]; //creates 2D Array that represents a square
  for(int i = 0; i<m_height; i++) //iterate through columns
  {
    for(int j = 0; j < m_width; j++) // iterate through rows
    {
      if((i+j<6)||(j-i>14)||(i-j>14)||(i+j>34)) // set corner pixels of square to 0
	m_mask[i*m_width+j] = 0;
      else
	m_mask[i*m_width+j] = 1; //set all pixels inside the cirlce to 1
    }
  }
  // Sets corner points that don't follow the distance formula above to 0
  m_mask[6]=0;
  m_mask[14]=0;
  m_mask[6*m_width]=0;
  m_mask[6*m_width+20]=0;
  m_mask[14*m_width]=0;
  m_mask[14*m_width+20]=0;
  m_mask[20*m_width+6]=0;
  m_mask[20*m_width+14]=0;
}
Eraser::~Eraser()
{}

//The draw function applies the current background color to everything inside the circle shaped mask and leaves all other pixles inside the array mask unchanged
void Eraser::draw(int x, int y, PixelBuffer *base)
{
   for(int i = 0; i<m_width; i++)
  {
    for(int j = 0; j < m_height; j++)
    {
      int height = y+i-(m_height/2);
      int width = x+j-(m_width/2);
      //Apply background color if pixel in mask is set to 1
      base->setPixel((width),(height), ((base->getBackgroundColor())*m_mask[i*m_width+j])+(base->getPixel(width,height)*(1.0-m_mask[i*m_width+j])));
      
      if(m_mask[i*m_width+j] != 0)
	    base->setPixel((width),(height), (base->getBackgroundColor()));
    }
  }
}
