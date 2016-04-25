//Blur Filter cpp file

#include "BlurFilter.h"
#include "Filter.h"
#include "ColorData.h"
#include <cmath>

BlurFilter::BlurFilter(){
	m_height = 41;
	m_width = 41;
	
	for(int i = 0; i<m_height; i++){
		for(int j = 0; j < m_width; j++){ //for pen in 3X3 array the circle can be easly represented as a cross through the 1s
			int x_dist, y_dist;
			float dist;
			
			y_dist = (m_height/2) - i; //y distance of pixel from the center pixel of mask
			x_dist = (m_width/2) - j; //x distance of pixel from the center pixel of mask
			dist = sqrt((x_dist* x_dist) +(y_dist * y_dist)); //Pythagorean's Theorem
			
			if(dist >= 20.0) //any distance over 20 is fully transparent
				kernal[i][j] = 0;
			
			else
				kernal[i][j] =((20.0-dist)/20.0);
		}
	}
	
}

BlurFilter::~BlurFilter(){}

void BlurFilter::apply(float amount, PixelBuffer* current){
	
	
	PixelBuffer * copy = new PixelBuffer(current->getWidth(),current->getHeight(),current->getBackgroundColor());
	copy->copyPixelBuffer(copy, current);
	for(int i=0; i<current->getHeight(); i++){
		for(int j= 0; j<current->getWidth(); j++){
			ColorData total(0,0,0);
			float counter=0;
			
			for(int p=0; p<41; p++){
				for(int w=0; w<41; w++){
					float dist;
					
					dist = kernal[p][w];
					//if valid pixel add to total and increment count
					if((j-20)+w >=0 && (j-20)+w < current->getWidth() && (i-20)+p >=0 && (i-20)+p < current->getHeight()){
						
						if(dist <= amount){ 
							total = total + copy->getPixel((j-20)+w,(i-20)+p);
							counter++;
						}
						
					}
					
				
				}
			}
			//averages total and clamps to make sure in range
			total = total* (1./counter);
			total.clampedColor();
			current->setPixel(j,i,total);
		}
	}
	delete copy;
	
}


