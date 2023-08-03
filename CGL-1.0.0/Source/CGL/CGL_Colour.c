
#ifndef CGL_COLOUR_C
#define CGL_COLOUR_C

#include "CGL_Type.h"
#include "CGL_Colour.h"

CGL_Colour CGL_CreateColour(CGL_UChar r, CGL_UChar g, CGL_UChar b)
{
    return (CGL_Colour){r, g, b};
}

#endif
