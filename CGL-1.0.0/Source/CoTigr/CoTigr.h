
#ifndef COTIGR_H
#define COTIGR_H

#include "tigr.h"
#include "CGL\CGL.h"

void CoTigr_BlitBitmap(Tigr *dest, CGL_Bitmap *src, int x, int y);

void CoTigr_ConvertBitmap(Tigr *dest, CGL_Bitmap *src);

#endif
