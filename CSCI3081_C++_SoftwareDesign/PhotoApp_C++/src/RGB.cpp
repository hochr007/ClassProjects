
#include "RGB.h"

RGB::RGB(){
	
}

RGB::~RGB(){}
//scales colors and clamps to range
void RGB::apply(float r, float g, float b, PixelBuffer * current)
{
	for(int i = 0; i < current->getHeight(); i++)
	{
		for(int j = 0; j < current->getWidth(); j++)
		{
			temp = current->getPixel(j,i);
			temp.setRed(r*temp.getRed());
			temp.setGreen(g*temp.getGreen());
			temp.setBlue(b*temp.getBlue());
			temp.clampedColor();
			current->setPixel(j,i, temp);
		}
	}
}
