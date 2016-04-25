
#include "Quantize.h"
#include <cmath>
#include <iostream>

Quantize::Quantize(){
	
}

Quantize::~Quantize(){}
//sets colors to x number of equaly spaced buckets
void Quantize::apply(int bins, PixelBuffer* current)
{
	for(int i = 0; i < current->getHeight(); i++)
	{
		for(int j = 0; j < current->getWidth(); j++)
		{
			float currentRed, currentGreen, currentBlue;
			float bestRed, bestGreen, bestBlue;
			float closeRed, closeGreen, closeBlue;
			currentRed = (current->getPixel(j,i)).getRed();
			currentGreen = (current->getPixel(j,i)).getGreen();
			currentBlue = (current->getPixel(j,i)).getBlue();
			closeRed = 12;
			closeGreen=12;
			closeBlue=12;
			
			for(int m = 0; m <bins; m++)
			{
				if(std::abs(currentRed-((float)m/((float)bins-1))) < closeRed)
				{
					closeRed = std::abs(currentRed-(float)((float)m/(float)(bins-1)));
					bestRed = (float)((float)m/(float)(bins-1));
				}
				if(std::abs(currentGreen-((float)m/((float)bins-1))) < closeGreen)
				{
					closeGreen = std::abs(currentGreen-(float)((float)m/(float)(bins-1)));
					bestGreen = (float)((float)m/(float)(bins-1));
				}
				if(std::abs(currentBlue-((float)m/((float)bins-1))) < closeBlue)
				{
					closeBlue = std::abs(currentBlue-(float)((float)m/(float)(bins-1)));
					bestBlue = (float)((float)m/(float)(bins-1));
				}
			}
			
			current->setPixel(j,i,ColorData(bestRed,bestGreen,bestBlue));
						
		}
	}
}
