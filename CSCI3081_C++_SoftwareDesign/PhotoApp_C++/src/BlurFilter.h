//Blur filter

#ifndef BLURFILTER_H
#define BLURFILTER_H

#include "Filter.h"
#include "PixelBuffer.h"

class BlurFilter : public Filter{
	public:
		BlurFilter();
		virtual ~BlurFilter();
		void apply(float var, PixelBuffer* current);
	private:
		int m_width;
		int m_height;
		float kernal[41][41];
};
#endif
