//Eraser.h

#ifndef ERASER_H
#define ERASER_H

#include "PixelBuffer.h"
#include "ColorData.h"
#include "Tool.h"

class Eraser: public Tool
{
 public:
  Eraser();
  virtual ~Eraser();
  void draw(int x, int y, PixelBuffer *base); 
};
#endif
