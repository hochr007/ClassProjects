
#include "Threshold.h"

Threshold::Threshold(){
	
}

Threshold::~Threshold(){}
//all colors bellow =0 all above =1
void Threshold::apply(float limit, PixelBuffer* current)
{
	for(int i = 0; i < current->getHeight(); i++)
	{
		for(int j = 0; j < current->getWidth(); j++)
		{
			float red,green,blue;
			if(current->getPixel(j,i).getRed() < limit)
				red =0;
			else 
				red = 1.0;
			if(current->getPixel(j,i).getGreen() < limit)
				green =0;
			else 
				green = 1.0;
			if(current->getPixel(j,i).getBlue() < limit)
				blue =0;
			else 
				blue = 1.0;
			current->setPixel(j,i, ColorData(red,green,blue));
		}
	}
}

