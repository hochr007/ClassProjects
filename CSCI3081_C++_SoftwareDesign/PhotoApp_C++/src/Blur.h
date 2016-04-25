//Blur.h
#ifndef BLUR_H
#define BLUR_H

#include "Tool.h"

class FlashPhotoApp;
//class PixelBuffer;

class Blur: public Tool
{
	public:
		Blur();
		virtual ~Blur();
		void draw(int x, int y, PixelBuffer* base);
	
	private:
};

#endif
