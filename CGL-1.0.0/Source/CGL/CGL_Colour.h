
#ifndef CGL_COLOUR_H
#define CGL_COLOUR_H

#include "CGL_Type.h"

typedef struct CGL_Colour
{
    CGL_UChar r, g, b;
} CGL_Colour;

CGL_Colour CGL_CreateColour(CGL_UChar r, CGL_UChar g, CGL_UChar b);

#define CGL_COLOUR_RED ((CGL_Colour){255, 0, 0})
#define CGL_COLOUR_DARK_RED ((CGL_Colour){100, 0, 0})
#define CGL_COLOUR_ORANGE ((CGL_Colour){255, 100, 0})
#define CGL_COLOUR_YELLOW ((CGL_Colour){255, 255, 0})
#define CGL_COLOUR_GOLD ((CGL_Colour){255, 200, 0})
#define CGL_COLOUR_LIME ((CGL_Colour){0, 255, 0})
#define CGL_COLOUR_GREEN ((CGL_Colour){0, 200, 0})
#define CGL_COLOUR_DARK_GREEN ((CGL_Colour){0, 100, 0})
#define CGL_COLOUR_LIGHT_BLUE ((CGL_Colour){0, 100, 255})
#define CGL_COLOUR_BLUE ((CGL_Colour){0, 0, 255})
#define CGL_COLOUR_DARK_BLUE ((CGL_Colour){0, 0, 200})
#define CGL_COLOUR_NAVY_BLUE ((CGL_Colour){0, 0, 100})
#define CGL_COLOUR_PURPLE ((CGL_Colour){100, 0, 255})
#define CGL_COLOUR_VIOLET ((CGL_Colour){200, 0, 255})
#define CGL_COLOUR_PINK ((CGL_Colour){255, 0, 255})

#endif
