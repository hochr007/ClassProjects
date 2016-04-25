//Stamp.cpp
#include "Stamp.h"
#include "Tool.h"
#include <iostream>

Stamp::Stamp()
{

	
}
Stamp::~Stamp(){}
//draws stamp from image buffer on valid pixels
void Stamp::draw(int x, int y, PixelBuffer* base, PixelBuffer* stampImage)
{
	int height = stampImage->getHeight();
	int width = stampImage->getWidth();
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			if(((x-(width/2)+j)>=0) && ((x-(width/2)+j) < base->getWidth()) && ((y-(height/2)+i)>=0) && ((y-(height/2)+i)< base->getHeight()))
				base->setPixel((x-(width/2)+j), (y-(height/2)+i), stampImage->getPixel(j,i));
		}
	}
	
}
