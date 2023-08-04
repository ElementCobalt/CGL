
#ifndef CGL_TRIANGLE_H
#define CGL_TRIANGLE_H

#include "CGL_Vec2.h"
#include "CGL_Colour.h"
#include "CGL_Bitmap.h"

typedef struct CGL_Triangle
{
    CGL_Vec2 a, b, c;
} CGL_Triangle;

static float CGL_MinVec2X(CGL_Vec2 a, CGL_Vec2 b, CGL_Vec2 c);
static float CGL_MaxVec2X(CGL_Vec2 a, CGL_Vec2 b, CGL_Vec2 c);

static float CGL_MinVec2Y(CGL_Vec2 a, CGL_Vec2 b, CGL_Vec2 c);
static float CGL_MaxVec2Y(CGL_Vec2 a, CGL_Vec2 b, CGL_Vec2 c);

static float CGL_CalculateEdges();

CGL_Triangle CGL_CreateTriangle(CGL_Vec2 a, CGL_Vec2 b, CGL_Vec2 c);
CGL_Triangle CGL_CreateTriangleFromVertices(CGL_Vec2 *vertices);

void CGL_DrawTriangle(CGL_Bitmap *bitmap, CGL_Triangle triangle, CGL_Colour colour);

#endif
