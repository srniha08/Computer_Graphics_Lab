#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>

void boundaryFill8(int x, int y, int fcol, int bcol)
{
    if (getpixel(x, y) == bcol)
    {
        delay(10);

        putpixel(x, y, fcol);
        boundaryFill8(x - 1, y, fcol, bcol);
        boundaryFill8(x + 1, y, fcol, bcol);
        boundaryFill8(x, y - 1, fcol, bcol);
        boundaryFill8(x, y + 1, fcol, bcol);
        boundaryFill8(x - 1, y + 1, fcol, bcol);
        boundaryFill8(x + 1, y + 1, fcol, bcol);
        boundaryFill8(x + 1, y - 1, fcol, bcol);
        boundaryFill8(x - 1, y - 1, fcol, bcol);
    }
}

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(WHITE);
    rectangle(100, 100, 130, 130);

    boundaryFill8(115, 115, 2, 0);

    getch();
    closegraph();
}
