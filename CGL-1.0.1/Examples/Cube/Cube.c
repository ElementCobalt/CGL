
/**
 * This is a demonstration application
 * that displays a rotatable cube
 */

#include "CoTigr.h"

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

int main()
{
    Tigr *window = tigrWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Cube Rendering", TIGR_FIXED);
    CGL_Bitmap bitmap = CGL_CreateBitmap(WINDOW_WIDTH, WINDOW_HEIGHT);

    /**
     * These are the vertices that make
     * up the planes for the cube
     */
    CGL_Vec3 frontPoints[] = {
        CGL_NewVec3(-100.0f, 100.0f, 100.0f),
        CGL_NewVec3(100.0f, 100.0f, 100.0f),
        CGL_NewVec3(-100.0f, -100.0f, 100.0f),
        CGL_NewVec3(100.0f, -100.0f, 100.0f)};

    CGL_Vec3 backPoints[] = {
        CGL_NewVec3(-100.0f, 100.0f, -100.0f),
        CGL_NewVec3(100.0f, 100.0f, -100.0f),
        CGL_NewVec3(-100.0f, -100.0f, -100.0f),
        CGL_NewVec3(100.0f, -100.0f, -100.0f)};

    CGL_Vec3 rightPoints[] = {
        CGL_NewVec3(100.0f, 100.0f, -100.0f),
        CGL_NewVec3(100.0f, 100.0f, 100.0f),
        CGL_NewVec3(100.0f, -100.0f, -100.0f),
        CGL_NewVec3(100.0f, -100.0f, 100.0f)};

    CGL_Vec3 leftPoints[] = {
        CGL_NewVec3(-100.0f, 100.0f, -100.0f),
        CGL_NewVec3(-100.0f, 100.0f, 100.0f),
        CGL_NewVec3(-100.0f, -100.0f, -100.0f),
        CGL_NewVec3(-100.0f, -100.0f, 100.0f)};

    CGL_Vec3 topPoints[] = {
        CGL_NewVec3(-100.0f, -100.0f, 100.0f),
        CGL_NewVec3(100.0f, -100.0f, 100.0f),
        CGL_NewVec3(-100.0f, -100.0f, -100.0f),
        CGL_NewVec3(100.0f, -100.0f, -100.0f)};

    CGL_Vec3 basePoints[] = {
        CGL_NewVec3(-100.0f, 100.0f, 100.0f),
        CGL_NewVec3(100.0f, 100.0f, 100.0f),
        CGL_NewVec3(-100.0f, 100.0f, -100.0f),
        CGL_NewVec3(100.0f, 100.0f, -100.0f)};

    CGL_Vec3 pos = CGL_NewVec3(200.0f, 200.0f, 200.0f);

    CGL_Plane front;
    CGL_Plane back;
    CGL_Plane right;
    CGL_Plane left;
    CGL_Plane top;
    CGL_Plane base;

    int i;

    while (!tigrClosed(window) && !tigrKeyDown(window, TK_ESCAPE))
    {
        /**
         * Collect keyboard input from
         * the user to rotate the cube
         */
        if (tigrKeyHeld(window, 'D'))
            for (i = 0; i < 4; ++i)
            {
                CGL_RotateYAxis(&frontPoints[i], 0.1f);
                CGL_RotateYAxis(&backPoints[i], 0.1f);
                CGL_RotateYAxis(&rightPoints[i], 0.1f);
                CGL_RotateYAxis(&leftPoints[i], 0.1f);
                CGL_RotateYAxis(&topPoints[i], 0.1f);
                CGL_RotateYAxis(&basePoints[i], 0.1f);
            }
        else if (tigrKeyHeld(window, 'A'))
            for (i = 0; i < 4; ++i)
            {
                CGL_RotateYAxis(&frontPoints[i], -0.1f);
                CGL_RotateYAxis(&backPoints[i], -0.1f);
                CGL_RotateYAxis(&rightPoints[i], -0.1f);
                CGL_RotateYAxis(&leftPoints[i], -0.1f);
                CGL_RotateYAxis(&topPoints[i], -0.1f);
                CGL_RotateYAxis(&basePoints[i], -0.1f);
            }
        else if (tigrKeyHeld(window, 'W'))
            for (i = 0; i < 4; ++i)
            {
                CGL_RotateXAxis(&frontPoints[i], 0.1f);
                CGL_RotateXAxis(&backPoints[i], 0.1f);
                CGL_RotateXAxis(&rightPoints[i], 0.1f);
                CGL_RotateXAxis(&leftPoints[i], 0.1f);
                CGL_RotateXAxis(&topPoints[i], 0.1f);
                CGL_RotateXAxis(&basePoints[i], 0.1f);
            }
        else if (tigrKeyHeld(window, 'S'))
            for (i = 0; i < 4; ++i)
            {
                CGL_RotateXAxis(&frontPoints[i], -0.1f);
                CGL_RotateXAxis(&backPoints[i], -0.1f);
                CGL_RotateXAxis(&rightPoints[i], -0.1f);
                CGL_RotateXAxis(&leftPoints[i], -0.1f);
                CGL_RotateXAxis(&topPoints[i], -0.1f);
                CGL_RotateXAxis(&basePoints[i], -0.1f);
            }

        /**
         * Create 2D renderable planes
         * from the vertices
         *
         * Note: Sometimes the order of
         * the vertices feed into CGL_CreatePlane
         * cannot be in order, as seen below
         *
         * This will hopefully be patched in a
         * future update
         */
        front = CGL_CreatePlane(
            CGL_Vec3ToVec2(CGL_AddVec3(frontPoints[0], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(frontPoints[2], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(frontPoints[1], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(frontPoints[3], pos)));

        back = CGL_CreatePlane(
            CGL_Vec3ToVec2(CGL_AddVec3(backPoints[0], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(backPoints[1], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(backPoints[2], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(backPoints[3], pos)));

        right = CGL_CreatePlane(
            CGL_Vec3ToVec2(CGL_AddVec3(rightPoints[0], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(rightPoints[1], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(rightPoints[2], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(rightPoints[3], pos)));

        left = CGL_CreatePlane(
            CGL_Vec3ToVec2(CGL_AddVec3(leftPoints[0], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(leftPoints[2], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(leftPoints[1], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(leftPoints[3], pos)));

        top = CGL_CreatePlane(
            CGL_Vec3ToVec2(CGL_AddVec3(topPoints[0], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(topPoints[2], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(topPoints[1], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(topPoints[3], pos)));

        base = CGL_CreatePlane(
            CGL_Vec3ToVec2(CGL_AddVec3(basePoints[0], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(basePoints[1], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(basePoints[2], pos)),
            CGL_Vec3ToVec2(CGL_AddVec3(basePoints[3], pos)));

        CGL_ClearBitmap(&bitmap, CGL_COLOUR_LIGHT_BLUE);

        /**
         * Render the 2D planes
         */
        CGL_DrawPlane(&bitmap, front, CGL_COLOUR_RED);
        CGL_DrawPlane(&bitmap, back, CGL_COLOUR_ORANGE);
        CGL_DrawPlane(&bitmap, right, CGL_COLOUR_YELLOW);
        CGL_DrawPlane(&bitmap, left, CGL_COLOUR_LIME);
        CGL_DrawPlane(&bitmap, top, CGL_COLOUR_PURPLE);
        CGL_DrawPlane(&bitmap, base, CGL_COLOUR_PINK);

        CoTigr_ConvertBitmap(window, &bitmap);
        tigrUpdate(window);
    }

    CGL_FreeBitmap(&bitmap);
    tigrFree(window);

    return 0;
}