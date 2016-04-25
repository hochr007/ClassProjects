//SprayCan.h

#ifndef SPRAYCAN_H
#define SPRAYCAN_H

#include "PixelBuffer.h"
#include "ColorData.h"
#include "Tool.h"

class SprayCan: public Tool
{
 public:
  SprayCan();
  virtual ~SprayCan();
  void draw(int x, int y, PixelBuffer *base);

};
#endif
