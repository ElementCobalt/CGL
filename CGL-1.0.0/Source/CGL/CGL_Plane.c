
#ifndef CGL_PLANE_C
#define CGL_PLANE_C

#include "CGL_Vec2.h"
#include "CGL_Triangle.h"
#include "CGL_Plane.h"

CGL_Plane CGL_CreatePlane(CGL_Vec2 a, CGL_Vec2 b, CGL_Vec2 c, CGL_Vec2 d)
{
    return (CGL_Plane){a, b, c, d};
}

CGL_Plane CGL_CreatePlaneFromTriangles(CGL_Triangle a, CGL_Triangle b)
{
    return (CGL_Plane){a.a, a.b, a.c, b.b};
}

void CGL_DrawPlane(CGL_Bitmap *bitmap, CGL_Plane plane, CGL_Colour colour)
{
    CGL_DrawTriangle(bitmap, CGL_CreateTriangle(plane.a, plane.d, plane.c), colour);
    CGL_DrawTriangle(bitmap, CGL_CreateTriangle(plane.a, plane.b, plane.d), colour);
}

#endif
