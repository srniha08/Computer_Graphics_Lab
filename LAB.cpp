#include<iostream>
#include<graphics.h>
#include<math.h>
int main()
{
 int gd=DETECT,gm;
 int x,y,x1,y1,x2,y2,x3,y3,shear_f,shear_g;
 int a,b,a1,b1,a2,b2,a3,b3;
 initgraph(&gd,&gm,"C:\TURBOC3\BGI");
 printf("\n please enter first coordinate = ");
 scanf("%d %d",&x,&y);
 printf("\n please enter second coordinate = ");
 scanf("%d %d",&x1,&y1);
 printf("\n please enter third coordinate = ");
 scanf("%d %d",&x2,&y2);
 printf("\n please enter last coordinate = ");
 scanf("%d %d",&x3,&y3);
 printf("\n please enter shearing factor x = ");
 scanf("%d",&shear_f);
 printf("\n please enter shearing factor  = ");
 scanf("%d",&shear_g);

 cleardevice();
 line(x,y,x1,y1);
 line(x1,y1,x2,y2);
 line(x2,y2,x3,y3);
 line(x3,y3,x,y);
 setcolor(YELLOW);
 x=x+ y*shear_f;
 x1=x1+ y1*shear_f;
 x2=x2+ y2*shear_f;
 x3=x3+ y3*shear_f;
 line(x,y,x1,y1);
 line(x1,y1,x2,y2);
 line(x2,y2,x3,y3);
 line(x3,y3,x,y);


 printf("\n please enter first coordinate = ");
 scanf("%d %d",&a,&b);
 printf("\n please enter second coordinate = ");
 scanf("%d %d",&a1,&b1);
 printf("\n please enter third coordinate = ");
 scanf("%d %d",&a2,&b2);
 printf("\n please enter last coordinate = ");
 scanf("%d %d",&a3,&b3);
 printf("\n please enter shearing factor y = ");
 scanf("%d",&shear_g);
 cleardevice();
 line(a,b,a1,b1);
 line(a1,b1,a2,b2);
 line(a2,b2,a3,b3);
 line(a3,b3,a,b);
 setcolor(GREEN);
 b=b+ a*shear_g;
 b1=b1+ a1*shear_g;
 b2=b2+ a2*shear_g;
 b3=b3+ a3*shear_g;
 line(a,b,a1,b1);
 line(a1,b1,a2,b2);
 line(a2,b2,a3,b3);
 line(a3,b3,a,b);
 getch();
 closegraph();
 }
