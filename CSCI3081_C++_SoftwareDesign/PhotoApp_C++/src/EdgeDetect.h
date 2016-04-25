//Edge detection filter

#ifndef EDGEDETECT_H
#define EDGEDETECT_H

#include "PixelBuffer.h"
#include "ColorData.h"
#include "Filter.h"


class EdgeDetect:public Filter{
	public:
		EdgeDetect();
		virtual ~EdgeDetect();
		void apply(PixelBuffer * current);
	private:
		int kernal[3][3];

};
#endif
