//Saturation


#ifndef SATURATION_H
#define SATURATION_H

#include "PixelBuffer.h"
#include "Filter.h"
#include "ColorData.h"


class Saturation: public Filter{
	public:
		Saturation();
		virtual ~Saturation();
		void apply(float x, PixelBuffer * current);
};
#endif
