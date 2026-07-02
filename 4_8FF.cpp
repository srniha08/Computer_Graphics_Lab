#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void floodFill4(int x, int y, int oldColor, int newColor)
{
    if (getpixel(x, y) == oldColor)
    {
        putpixel(x, y, newColor);
        floodFill4(x + 1, y, oldColor, newColor);
        floodFill4(x - 1, y, oldColor, newColor);
        floodFill4(x, y + 1, oldColor, newColor);
        floodFill4(x, y - 1, oldColor, newColor);
    }
}

void floodFill8(int x, int y, int oldColor, int newColor)
{
    if (getpixel(x, y) == oldColor)
    {
        putpixel(x, y, newColor);
        floodFill8(x + 1, y, oldColor, newColor);
        floodFill8(x - 1, y, oldColor, newColor);
        floodFill8(x, y + 1, oldColor, newColor);
        floodFill8(x, y - 1, oldColor, newColor);
        floodFill8(x + 1, y + 1, oldColor, newColor);
        floodFill8(x - 1, y - 1, oldColor, newColor);
        floodFill8(x + 1, y - 1, oldColor, newColor);
        floodFill8(x - 1, y + 1, oldColor, newColor);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    setcolor(WHITE);
    // Draw first rectangle/cube boundary
    rectangle(50, 100, 200, 250);

    outtextxy(50, 70, "4-Connected Flood Fill Operation");
    outtextxy(50, 85, "Changing color from BLACK to GREEN");

    // Perform 4-connected flood fill
    floodFill4(125, 175, BLACK, GREEN);

    setcolor(WHITE);
    // Draw second rectangle/cube boundary
    rectangle(350, 100, 500, 250);

    // Output text describing the operation on the graphics screen
    outtextxy(350, 70, "8-Connected Flood Fill Operation");
    outtextxy(350, 85, "Changing color from BLACK to RED");

    // Perform 8-connected flood fill
    floodFill8(425, 175, BLACK, RED);

    getch();
    closegraph();
    return 0;
}
