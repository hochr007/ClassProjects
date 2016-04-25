//sharpen file for the class

#include "Sharpen.h"
#include <iostream>

Sharpen::Sharpen(){
	
}

Sharpen::~Sharpen(){}

void Sharpen::apply(float amount,PixelBuffer* current)
{
	//dynamicly allocate the kernal based upon the 
	kernal = new float[3*3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(i==1&&j==1)
				kernal[i*3+j]=amount;
			else
				kernal[i*3+j]=-((amount-1.0)/8.0);
			}
	}
				std::cout<<kernal[3]<<std::endl;
	
	PixelBuffer * copy = new PixelBuffer(current->getWidth(),current->getHeight(),current->getBackgroundColor());
	copy->copyPixelBuffer(copy, current);
	//apply the filter using the kernal
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

					color= ((copy->getPixel(width,height))*kernal[m*3+n]) + color;
						
				}
			}			
			color = color.clampedColor();
			current->setPixel(j,i,color);      
		}
	}
	delete copy;
	delete kernal;
}
