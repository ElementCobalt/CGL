
#ifndef CGL_TRIANGLE_C
#define CGL_TRIANGLE_C

#include "CGL_Vec2.h"
#include "CGL_Vec3.h"
#include "CGL_Bitmap.h"
#include "CGL_Colour.h"
#include "CGL_Triangle.h"

static float CGL_MinVec2X(CGL_Vec2 a, CGL_Vec2 b, CGL_Vec2 c)
{
    int x = (a.x <= b.x) ? a.x : b.x;
    return (x <= c.x) ? x : c.x;
}

static float CGL_MaxVec2X(CGL_Vec2 a, CGL_Vec2 b, CGL_Vec2 c)
{
    int x = (a.x >= b.x) ? a.x : b.x;
    return (x >= c.x) ? x : c.x;
}

static float CGL_MinVec2Y(CGL_Vec2 a, CGL_Vec2 b, CGL_Vec2 c)
{
    int y = (a.y <= b.y) ? a.y : b.y;
    return (y <= c.y) ? y : c.y;
}

static float CGL_MaxVec2Y(CGL_Vec2 a, CGL_Vec2 b, CGL_Vec2 c)
{
    int y = (a.y >= b.y) ? a.y : b.y;
    return (y >= c.y) ? y : c.y;
}

static float CGL_CalculateEdge(CGL_Vec2 a, CGL_Vec2 b, CGL_Vec2 c)
{
    return ((b.x - a.x) * (c.y - a.y)) - ((b.y - a.y) * (c.x - a.x));
}

CGL_Triangle CGL_CreateTriangle(CGL_Vec2 a, CGL_Vec2 b, CGL_Vec2 c)
{
    return (CGL_Triangle){a, b, c};
}

CGL_Triangle CGL_CreateTriangleFromVertices(CGL_Vec2 *vertices)
{
    return (CGL_Triangle){*(vertices), *(vertices + 1), *(vertices + 2)};
}

void CGL_DrawTriangle(CGL_Bitmap *bitmap, CGL_Triangle triangle, CGL_Colour colour)
{
    for (int x = CGL_MinVec2X(triangle.a, triangle.b, triangle.c); x < CGL_MaxVec2X(triangle.a, triangle.b, triangle.c); ++x)
        for (int y = CGL_MinVec2Y(triangle.a, triangle.b, triangle.c); y < CGL_MaxVec2Y(triangle.a, triangle.b, triangle.c); ++y)
            if (CGL_CalculateEdge(triangle.a, triangle.b, (CGL_Vec2){x, y}) >= 0.0f &&
                CGL_CalculateEdge(triangle.b, triangle.c, (CGL_Vec2){x, y}) >= 0.0f &&
                CGL_CalculateEdge(triangle.c, triangle.a, (CGL_Vec2){x, y}) >= 0.0f)
                *(bitmap->colour + ((bitmap->width * y) + x)) = colour;
}

#endif
