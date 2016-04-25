
#include "Special.h"

Special::Special(){
	
}

Special::~Special(){}
//sepia filter causes all colors to become shades of brown
//western feel
void Special::apply(PixelBuffer* current)
{
	for(int i = 0; i < current->getHeight(); i++)
	{
		for(int j = 0; j < current->getWidth(); j++)
		{
			float red,green,blue,cRed,cGreen,cBlue;
			cRed=current->getPixel(j,i).getRed();
			cGreen=current->getPixel(j,i).getGreen();
			cBlue=current->getPixel(j,i).getBlue();
			red = (cRed * .393) + (cGreen *.769) + (cBlue * .189);
			green = (cRed * .349) + (cGreen *.686) + (cBlue * .168);
			blue = (cRed * .272) + (cGreen *.534) + (cBlue * .131);
			current->setPixel(j,i,ColorData(red,green,blue).clampedColor());

		}
	}
}
