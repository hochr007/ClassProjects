//Edge Detect cpp file

#include "MotionBlur.h"
#include "ColorData.h"
#include "Filter.h"
#include <cmath>
#include <iostream>

MotionBlur::MotionBlur(){
	//need to create 4 masks
	for(int i=0; i<41; i++){
		for(int j=0; j<41; j++){
			if (i==j){
				m_mask2[i][j] = 1;
			}
			if(i==20){
				m_mask1[i][j] = 1;
			}
			if(j==20){
				m_mask0[i][j] = 1;
			}
			if((40-j) == i){
				m_mask3[i][j] = 1;
			}
		}
	}
	m_height = 41;
	m_width = 41;
	
	for(int i = 0; i<m_height; i++){
		for(int j = 0; j < m_width; j++){ 
			int x_dist, y_dist;
			float dist;
			
			y_dist = (m_height/2) - i; //y distance of pixel from the center pixel of mask
			x_dist = (m_width/2) - j; //x distance of pixel from the center pixel of mask
			dist = sqrt((x_dist* x_dist) +(y_dist * y_dist)); //Pythagorean's Theorem
			
			if(dist >= 20.0) //any distance over 20 is fully transparent
				dist_mask[i][j] = 0;
			
			else
				dist_mask[i][j] =((20.0-dist)/20.0);
		}
	}
}
//applies the correct blur for the direction
void MotionBlur::apply(float amount, int direction, PixelBuffer* current){
	//0 is northsouth
	//1 is east west
	//2 is northeast to southwest
	//3 is northwest to southeast
	
	PixelBuffer * copy = new PixelBuffer(current->getWidth(),current->getHeight(),current->getBackgroundColor());
	copy->copyPixelBuffer(copy, current);
	
	for (int i=0; i<current->getHeight(); i++){
		for (int j=0; j<current->getWidth(); j++){
			ColorData total(0,0,0);
			float counter=0;
			
			for(int p=0; p<m_height; p++){
				for(int w=0; w<m_width; w++){
					float dist = dist_mask[p][w];
					
					if(j-20+w >=0 && j-20+w < current->getWidth() && i-20+p >= 0 && i-20+p < current->getHeight()){
						
						if(dist <= amount){
							if(direction==0){
								total = total + copy->getPixel(j-20+w, i-20+p)*m_mask0[p][w];
								counter += 1.*m_mask0[p][w];
							}
							if(direction==1){
								total = total + copy->getPixel(j-20+w, i-20+p)*m_mask1[p][w];
								counter += 1.*m_mask1[p][w];
							}
							if(direction==2){
								total = total + copy->getPixel(j-20+w, i-20+p)*m_mask2[p][w];
								counter += 1.*m_mask2[p][w];
							}
							if(direction==3){
								total = total + copy->getPixel(j-20+w, i-20+p)*m_mask3[p][w];
								counter += 1.*m_mask3[p][w];
							}
						}
					}
				}
			}
			//averages and sets
			total = total* (1./counter);
			total.clampedColor();
			current->setPixel(j,i,total);
		}
	}
	
	delete copy;
}

MotionBlur::~MotionBlur(){}
