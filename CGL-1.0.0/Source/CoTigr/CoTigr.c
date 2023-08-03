
#ifndef COTIGR_C
#define COTIGR_C

#include "tigr.h"
#include "CGL\CGL.h"
#include "CoTigr.h"

void CoTigr_BlitBitmap(Tigr *dest, CGL_Bitmap *src, int x, int y)
{
    for (int xp = 0; xp < src->width; ++xp)
    {
        for (int yp = 0; yp < src->height; ++yp)
        {
            CGL_Colour c = CGL_GetColour(src, x, y);
            tigrPlot(dest, xp + x, y + yp, tigrRGB(c.r, c.g, c.b));
        }
    }
}

void CoTigr_ConvertBitmap(Tigr *dest, CGL_Bitmap *src)
{
    if (dest->w != src->width || dest->h != src->height)
        return;

    for (int x = 0; x < dest->w; ++x)
    {
        for (int y = 0; y < dest->h; ++y)
        {
            CGL_Colour c = CGL_GetColour(src, x, y);
            tigrPlot(dest, x, y, tigrRGB(c.r, c.g, c.b));
        }
    }
}

#endif
