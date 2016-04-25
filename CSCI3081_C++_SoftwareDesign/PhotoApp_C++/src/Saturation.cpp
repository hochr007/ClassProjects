


#include "Saturation.h"
#include <iostream>

Saturation::Saturation(){
	
}

Saturation::~Saturation(){}
//adjusts saturation level 
//0=greyscale 1 = normal -1 = invert
void Saturation::apply(float x, PixelBuffer* current)
{
	float grey;
	for(int i = 0; i < current->getHeight(); i++)
	{
		for(int j = 0; j < current->getWidth(); j++)
		{
			grey = current->getPixel(j,i).getLuminance();
			current->setPixel(j,i,((current->getPixel(j,i))*x+((ColorData(grey,grey,grey))*(1-x))).clampedColor());
			
		}
	}
}
