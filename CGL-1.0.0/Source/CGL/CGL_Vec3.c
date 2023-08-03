
#ifndef CGL_VEC3_C
#define CGL_VEC3_C

#include "CGL_Vec3.h"

CGL_Vec3 CGL_NewVec3(float x, float y, float z)
{
    return (CGL_Vec3){x, y, z};
}

CGL_Vec3 CGL_AddVec3(CGL_Vec3 a, CGL_Vec3 b)
{
    return (CGL_Vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

#endif
