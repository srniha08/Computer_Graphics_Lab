#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void flood(int, int, int, int);
void main()
{
    int gd, gm=DETECT;
    clrscr();
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm);
}
