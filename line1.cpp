#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

void main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI" );
    line(100,120,150,180);
    getch();
}
