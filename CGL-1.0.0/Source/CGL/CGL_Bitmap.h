
#ifndef CGL_BITMAP_H
#define CGL_BITMAP_H

#include "CGL_Type.h"
#include "CGL_Colour.h"

typedef struct CGL_Bitmap
{
    CGL_Colour *colour;
    CGL_UInt width, height;
} CGL_Bitmap;

CGL_Bitmap CGL_CreateBitmap(CGL_UInt width, CGL_UInt height);

CGL_Colour CGL_GetColour(CGL_Bitmap *bitmap, CGL_UInt x, CGL_UInt y);

void CGL_PlotColour(CGL_Bitmap *bitmap, CGL_Colour colour, CGL_UInt x, CGL_UInt y);

void CGL_ClearBitmap(CGL_Bitmap *bitmap, CGL_Colour colour);

void CGL_FreeBitmap(CGL_Bitmap *bitmap);

#endif
