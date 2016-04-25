
#ifndef SPECIAL_H
#define SPECIAL_H

#include "PixelBuffer.h"
#include "Filter.h"
#include "ColorData.h"


class Special: public Filter{
	public:
		Special();
		virtual ~Special();
		void apply(PixelBuffer* current);
};
#endif
