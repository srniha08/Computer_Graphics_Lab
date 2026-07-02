#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

void drawBezier(int x0, int y0,
                int x1, int y1,
                int x2, int y2,
                int x3, int y3)
{
    float t;
    int px, py;

    for (t = 0.0; t <= 1.0; t += 0.001)
    {
        float u = 1.0 - t;
        float u2 = u * u;
        float u3 = u2 * u;
        float t2 = t * t;
        float t3 = t2 * t;

        px = (int)(u3 * x0 + 3 * u2 * t * x1 + 3 * u * t2 * x2 + t3 * x3);
        py = (int)(u3 * y0 + 3 * u2 * t * y1 + 3 * u * t2 * y2 + t3 * y3);

        putpixel(px, py, WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;
    int x0, y0, x1, y1, x2, y2, x3, y3;

    printf("Enter Bezier Curve Control Points:\n");

    printf("P0 (x y): ");
    scanf("%d %d", &x0, &y0);

    printf("P1 (x y): ");
    scanf("%d %d", &x1, &y1);

    printf("P2 (x y): ");
    scanf("%d %d", &x2, &y2);

    printf("P3 (x y): ");
    scanf("%d %d", &x3, &y3);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    cleardevice();

    // DRAW BEZIER CURVE
    drawBezier(x0, y0, x1, y1, x2, y2, x3, y3);

    // CONTROL POLYGON
    setcolor(YELLOW);
    line(x0, y0, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);

    setcolor(WHITE);
    outtextxy(10, 10, "WHITE: Bezier Curve");
    outtextxy(10, 30, "YELLOW: Control Polygon Lines");

    getch();
    closegraph();

    return 0;
}
