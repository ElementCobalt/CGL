
#ifndef CGL_VEC2_H
#define CGL_VEC2_H

typedef struct CGL_Vec2
{
    float x, y;
} CGL_Vec2;

CGL_Vec2 CGL_NewVec2(float x, float y);

CGL_Vec2 CGL_AddVec2(CGL_Vec2 a, CGL_Vec2 b);

#endif
