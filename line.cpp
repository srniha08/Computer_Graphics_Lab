// LINE PROGRAM

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    line(200, 210, 250, 300);

    getch();
    closegraph();
}
