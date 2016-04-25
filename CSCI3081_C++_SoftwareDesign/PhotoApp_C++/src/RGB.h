//RGB filter

#ifndef RGB_H
#define RGB_H

#include "PixelBuffer.h"
#include "ColorData.h"
#include "Filter.h"


class RGB: public Filter{
	public:
		RGB();
		virtual ~RGB();
		void apply(float r ,float g, float b, PixelBuffer* current);
	private:
		ColorData temp;
};
#endif
