//Edge Detect cpp file

#include "EdgeDetect.h"
#include <iostream>
//creates kernal
EdgeDetect::EdgeDetect(){
	for(int i=0; i<(3); i++)
	{
		for(int j=0; j<3;j++)
		{
			if (i==1&&j==1)
				kernal[i][j] = 8;
			else
				kernal[i][j] = -1;
		}
	}
}

EdgeDetect::~EdgeDetect(){}
//applys kernal
void EdgeDetect::apply(PixelBuffer* current)
{
	PixelBuffer * copy = new PixelBuffer(current->getWidth(),current->getHeight(),current->getBackgroundColor());
	copy->copyPixelBuffer(copy, current);
	for(int i = 0; i<current->getHeight(); i++)
	{
		for(int j = 0; j < current->getWidth(); j++)
		{
			ColorData color(0,0,0);
			for(int m =0; m<3 ;m++)
			{
				for(int n = 0; n<3; n++)
				{
					int height = i+m-(3/2);
					int width = n+j-(3/2);

					color= ((copy->getPixel(width,height))*kernal[m][n]) + color;
						
				}
			}
			//clamp so under 1 and over 0
			color = color.clampedColor();
			current->setPixel(j,i,color);

      
		}
	}
	delete copy;
}
