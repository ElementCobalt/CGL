
#ifndef CGL_VEC2_C
#define CGL_VEC2_C

#include "CGL_Vec2.h"

CGL_Vec2 CGL_NewVec2(float x, float y)
{
    return (CGL_Vec2){x, y};
}

CGL_Vec2 CGL_AddVec2(CGL_Vec2 a, CGL_Vec2 b)
{
    return (CGL_Vec2){a.x + b.x, a.y + b.y};
}

CGL_Vec2 CGL_SubVec2(CGL_Vec2 a, CGL_Vec2 b)
{
    return (CGL_Vec2){a.x - b.x, a.y - b.y};
}

CGL_Vec2 CGL_MulVec2(CGL_Vec2 a, CGL_Vec2 b)
{
    return (CGL_Vec2){a.x * b.x, a.y * b.y};
}

CGL_Vec2 CGL_DivVec2(CGL_Vec2 a, CGL_Vec2 b)
{
    return (CGL_Vec2){a.x / b.x, a.y / b.y};
}

#endif
