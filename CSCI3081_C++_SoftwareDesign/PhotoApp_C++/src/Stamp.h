//Stamp.h
#ifndef STAMP_H
#define STAMP_H


#include "Tool.h"
#include "PixelBuffer.h"
#include "ColorData.h"

class Stamp: public Tool
{
 public:
  Stamp();
  virtual ~Stamp();
  void draw(int x, int y, PixelBuffer* base, PixelBuffer* stampImage);
 private:
	const ColorData* array;

};
#endif
