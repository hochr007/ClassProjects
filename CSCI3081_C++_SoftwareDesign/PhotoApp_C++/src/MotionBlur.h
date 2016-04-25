//Edge detection filter

#ifndef MOTIONBLUR_H
#define MOTIONBLUR_H

#include "PixelBuffer.h"
#include "Filter.h"


class MotionBlur : public Filter{
	public:
		MotionBlur();
		virtual ~MotionBlur();
		void apply(float amount, int direction, PixelBuffer* current);
		
	private:
		float m_mask0[41][41]; //north-south
		float m_mask1[41][41]; //east-west
		float m_mask2[41][41]; //northeast-southwest
		float m_mask3[41][41]; //northwest-southeast
		float dist_mask[41][41];
		int m_width, m_height;
};
#endif
