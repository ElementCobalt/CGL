
#ifndef CGL_BITMAP_C
#define CGL_BITMAP_C

#include <stdlib.h>
#include "CGL_Type.h"
#include "CGL_Bitmap.h"

CGL_Bitmap CGL_CreateBitmap(CGL_UInt width, CGL_UInt height)
{
    return (CGL_Bitmap){(CGL_Colour *)calloc(width * height, sizeof(CGL_Colour)),
                        width,
                        height};
}

CGL_Colour CGL_GetColour(CGL_Bitmap *bitmap, CGL_UInt x, CGL_UInt y)
{
    return *(bitmap->colour + ((bitmap->width * y) + x));
}

void CGL_PlotColour(CGL_Bitmap *bitmap, CGL_Colour colour, CGL_UInt x, CGL_UInt y)
{
    *(bitmap->colour + ((bitmap->width * y) + x)) = colour;
}

void CGL_ClearBitmap(CGL_Bitmap *bitmap, CGL_Colour colour)
{
    for (CGL_UInt i = 0; i < bitmap->width * bitmap->height; ++i)
        *(bitmap->colour + i) = colour;
}

void CGL_FreeBitmap(CGL_Bitmap *bitmap)
{
    free(bitmap->colour);
    bitmap->colour = NULL;
}

#endif
