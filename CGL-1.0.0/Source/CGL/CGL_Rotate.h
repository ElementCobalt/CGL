

#ifndef CGL_ROTATE_H
#define CGL_ROTATE_H

#include "CGL_Vec3.h"

void CGL_RotateXAxis(CGL_Vec3 *point, float angle);

void CGL_RotateYAxis(CGL_Vec3 *point, float angle);

void CGL_RotateZAxis(CGL_Vec3 *point, float angle);

void CGL_RotateXYZ(CGL_Vec3 *point, CGL_Vec3 angle);

#endif
