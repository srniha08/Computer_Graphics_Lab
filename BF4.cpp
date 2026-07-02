#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>

void boundaryFill4(int x, int y, int fcol, int bcol)
{
    int current = getpixel(x, y);
    if (current != bcol && current != fcol)
    {
        delay(5);
        putpixel(x, y, fcol);
        boundaryFill4(x + 1, y, fcol, bcol);
        boundaryFill4(x - 1, y, fcol, bcol);
        boundaryFill4(x, y + 1, fcol, bcol);
        boundaryFill4(x, y - 1, fcol, bcol);
    }
}

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(WHITE);
    rectangle(100, 100, 140, 140);

    boundaryFill4(120, 120, 4, 15);

    getch();
    closegraph();
}
