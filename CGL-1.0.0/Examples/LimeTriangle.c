
// CoTigr already includes both the CGL and Tigr libraries
#include "..\Source\CoTigr\CoTigr.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

int main()
{
    // Create a Tigr window
    Tigr *window = tigrWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Lime Triangle", TIGR_FIXED);

    // Create a CGL bitmap
    CGL_Bitmap bitmap = CGL_CreateBitmap(SCREEN_WIDTH, SCREEN_HEIGHT);

    // An array of vertexes to store the triangle
    CGL_Vec2 vertices[] = {
        CGL_NewVec2(300.0f, 0.0f),
        CGL_NewVec2(600.0f, 400.0f),
        CGL_NewVec2(0.0f, 400.0f)};

    // Clear the bitmap with a pink colour
    CGL_ClearBitmap(&bitmap, CGL_COLOUR_PINK);

    // Draw a triangle from the vertices
    CGL_DrawTriangle(&bitmap, CGL_CreateTriangleFromVertices(vertices), CGL_COLOUR_LIME);

    // Convert the CGL_Bitmap to a Tigr bitmap
    CoTigr_ConvertBitmap(window, &bitmap);

    // Keep the window open with a simple loop
    while (!tigrClosed(window))
    {
        tigrUpdate(window);
    }

    // Delete the bitmap data
    CGL_FreeBitmap(&bitmap);
    tigrFree(window);

    return 0;
}
