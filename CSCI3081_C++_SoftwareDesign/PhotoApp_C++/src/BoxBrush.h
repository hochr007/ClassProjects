//BoxBrush.h

#ifndef BOXBRUSH_H
#define BOXBRUSH_H

#include "PixelBuffer.h"
#include "ColorData.h"
#include "Tool.h"

class BoxBrush: public Tool
{
 public:
  BoxBrush();
  virtual ~BoxBrush();
  void drawEdge(int x, int y, PixelBuffer *base); 

};
#endif
