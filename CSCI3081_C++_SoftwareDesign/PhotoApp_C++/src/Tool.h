//Tool.h

#ifndef TOOL_H
#define TOOL_H
//#include "ColorData.h"
class PixelBuffer;
class ColorData;
class Tool
{
 public:
  Tool();
  Tool(int toolNumber);
  virtual ~Tool();
  void setColor(float red, float green, float blue);
  virtual void draw(int x, int y, PixelBuffer *base);
  virtual void draw(int x, int y, PixelBuffer *base, PixelBuffer* stampImage);
  virtual void drawEdge(int x, int y, PixelBuffer *base);
 protected:
  ColorData *m_colors;
  float *m_mask;
  int m_width;
  int m_height;

  
  
};
#endif
