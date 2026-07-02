#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    for(int i=0;i<300;i++)
    {
        cleardevice();

        line(0,300,640,300); // road

        circle(100+i,200,20); // head
        line(100+i,220,100+i,270);

        for(int r=0;r<300;r+=20)
            line(r,0,r+10,20); // rain

        delay(30);
    }

    getch();
    closegraph();
}
