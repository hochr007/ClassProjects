//Sharpen filter

#ifndef SHARPEN_H
#define SHARPEN_H

#include "PixelBuffer.h"
#include "ColorData.h"
#include "Filter.h"

class Sharpen:public Filter
{
	public:
		Sharpen();
		virtual ~Sharpen();
		void apply(float amount,PixelBuffer* current);
	private:
		float* kernal;
};
#endif
