#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14159265

// Draw cube
void drawCube(int x[], int y[], int color)
{
    int i;
    setcolor(color);

    for (i = 0; i < 3; i++)
        line(x[i], y[i], x[i + 1], y[i + 1]);
    line(x[3], y[3], x[0], y[0]);

    for (i = 4; i < 7; i++)
        line(x[i], y[i], x[i + 1], y[i + 1]);
    line(x[7], y[7], x[4], y[4]);

    for (i = 0; i < 4; i++)
        line(x[i], y[i], x[i + 4], y[i + 4]);
}

// Translation
void translate(int x[], int y[], int xt[], int yt[],
               int tx, int ty)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        xt[i] = x[i] + tx;
        yt[i] = y[i] + ty;
    }
}

// Rotation
void rotateCube(int x[], int y[], int xr[], int yr[],
                float angle)
{
    int i;
    float rad = angle * PI / 180.0;
    float cosA = cos(rad);
    float sinA = sin(rad);

    for (i = 0; i < 8; i++)
    {
        xr[i] = (int)(x[i] * cosA - y[i] * sinA);
        yr[i] = (int)(x[i] * sinA + y[i] * cosA);
    }
}

// Scaling
void scaleCube(int x[], int y[], int xs[], int ys[],
               float sx, float sy)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        xs[i] = (int)(x[i] * sx);
        ys[i] = (int)(y[i] * sy);
    }
}

int main()
{
    int gd = DETECT, gm;
    int i;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // ORIGINAL CUBE
    int x[8] = {250, 310, 310, 250,
                280, 340, 340, 280};

    int y[8] = {60, 60, 120, 120,
                30, 30, 90, 90};

    int xt[8], yt[8];
    int xr[8], yr[8];
    int xs[8], ys[8];

    drawCube(x, y, WHITE);

    // ---------------- TRANSLATION ----------------
    translate(x, y, xt, yt, -170, 170);
    drawCube(xt, yt, GREEN);

    outtextxy(70, 330, "Translation");

    // ---------------- ROTATION ----------------
    rotateCube(x, y, xr, yr, 30);

    for (i = 0; i < 8; i++)
    {
        xr[i] += 120;
        yr[i] += 180;
    }

    drawCube(xr, yr, RED);

    outtextxy(240, 435, "Rotation");

    // ---------------- SCALING ----------------
    scaleCube(x, y, xs, ys, 0.8, 0.8);

    for (i = 0; i < 8; i++)
    {
        xs[i] += 250;
        ys[i] += 180;
    }

    drawCube(xs, ys, YELLOW);
    outtextxy(430, 330, "Scaling");

    getch();
    closegraph();

    return 0;
}
