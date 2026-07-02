#include<graphics.h>
#include<conio.h>
#include<dos.h>
void main()
{
 int gd = DETECT, gm;
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
 int i, j;
 for(i=0; i<400; i++)
 {
 cleardevice();
 // Cloudy Sky
 setbkcolor(BLUE);
 // Rain
 for(j=0; j<640; j=j+20)
 {
 line(j,0,j+10,20);
 }
 // Sun
 setcolor(WHITE);
 circle(550,80,40);
 // Road
 line(0,400,640,400);
 // Walking Man
 // Head
 circle(100+i,300,20);
 // Body
 line(100+i,320,100+i,380);
 // Hands
 line(100+i,340,80+i,360);
 line(100+i,340,120+i,360);
 // Legs
 line(100+i,380,80+i,420);
 line(100+i,380,120+i,420);
 delay(50);
 }
 getch();
 closegraph();
}
