
#ifndef CGL_ROTATE_C
#define CGL_ROTATE_C

#include <math.h>
#include "CGL_Vec3.h"
#include "CGL_Rotate.h"

void CGL_RotateXAxis(CGL_Vec3 *point, float angle)
{
    CGL_Vec3 oldPos = *point;

    point->y = (oldPos.y * cosf(angle)) - (oldPos.z * sinf(angle));
    point->z = (oldPos.y * sinf(angle)) + (oldPos.z * cosf(angle));
}

void CGL_RotateYAxis(CGL_Vec3 *point, float angle)
{
    CGL_Vec3 oldPos = *point;

    point->x = (oldPos.x * cosf(angle)) + (oldPos.z * sinf(angle));
    point->z = -(oldPos.x * sinf(angle)) + (oldPos.z * cosf(angle));
}

void CGL_RotateZAxis(CGL_Vec3 *point, float angle)
{
    CGL_Vec3 oldPos = *point;

    point->x = (oldPos.x * cosf(angle)) - (oldPos.y * sinf(angle));
    point->y = -(oldPos.x * sinf(angle)) + (oldPos.y * cosf(angle));
}

void CGL_RotateXYZ(CGL_Vec3 *point, CGL_Vec3 angle)
{
    CGL_RotateXAxis(point, angle.x);
    CGL_RotateYAxis(point, angle.y);
    CGL_RotateZAxis(point, angle.z);
}

#endif
