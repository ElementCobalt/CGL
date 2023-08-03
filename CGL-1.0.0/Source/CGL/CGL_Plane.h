
#ifndef CGL_PLANE_H
#define CGL_PLANE_H

#include "CGL_Bitmap.h"
#include "CGL_Triangle.h"
#include "CGL_Vec2.h"

typedef struct CGL_Plane
{
    CGL_Vec2 a, b, c, d;
} CGL_Plane;

CGL_Plane CGL_CreatePlane(CGL_Vec2 a, CGL_Vec2 b, CGL_Vec2 c, CGL_Vec2 d);

CGL_Plane CGL_CreatePlaneFromTriangles(CGL_Triangle a, CGL_Triangle b);

void CGL_DrawPlane(CGL_Bitmap *bitmap, CGL_Plane plane, CGL_Colour colour);

#endif
