

#ifndef THRESHOLD_H
#define THRESHOLD_H

#include "PixelBuffer.h"
#include "ColorData.h"
#include "Filter.h"


class Threshold: public Filter{
	public:
		Threshold();
		virtual ~Threshold();
		void apply(float limit, PixelBuffer* current);
};
#endif

