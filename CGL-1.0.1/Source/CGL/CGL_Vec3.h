
#ifndef CGL_VEC3_H
#define CGL_VEC3_H

typedef struct CGL_Vec3
{
    float x, y, z;
} CGL_Vec3;

CGL_Vec3 CGL_NewVec3(float x, float y, float z);

CGL_Vec3 CGL_AddVec3(CGL_Vec3 a, CGL_Vec3 b);

#endif
