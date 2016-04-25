
#ifndef QUANTIZE_H
#define QUANTIZE_H

#include "PixelBuffer.h"
#include "ColorData.h"
#include "Filter.h"


class Quantize{
	public:
		Quantize();
		virtual ~Quantize();
		void apply(int bins, PixelBuffer* current);
	
};
#endif
