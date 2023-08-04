
#ifndef CGL_VECTOR_C
#define CGL_VECTOR_C

#include "CGL_Vec2.h"
#include "CGL_Vec3.h"
#include "CGL_Vector.h"

CGL_Vec2 CGL_Vec3ToVec2(CGL_Vec3 vector)
{
    return (CGL_Vec2){vector.x, vector.y};
}

CGL_Vec3 CGL_Vec2ToVec3(CGL_Vec2 vector, float z)
{
    return (CGL_Vec3){vector.x, vector.y, z};
}

#endif
