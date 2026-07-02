#include<stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>

void floodFill8(int x, int y, int oldColor, int newColor)
{
    if (getpixel(x, y) == oldColor)
    {
        delay(5);
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

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(WHITE);
    rectangle(100, 100, 150, 150);

    floodFill8(125, 125, 0, 2);

    getch();
    closegraph();
}
