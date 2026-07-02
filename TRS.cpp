#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

void drawRect(int x1, int y1, int x2, int y2, int color)
{
    setcolor(color);

    line(x1, y1, x2, y1);
    line(x2, y1, x2, y2);
    line(x2, y2, x1, y2);
    line(x1, y2, x1, y1);
}

// Translation
void translate(int x1, int y1, int x2, int y2)
{
    drawRect(x1 + 80, y1 + 180, x2 + 80, y2 + 180, GREEN);
}

// Scaling
void scale(int x1, int y1, int x2, int y2)
{
    float sx = 1.3, sy = 1.3;

    int newX2 = x1 + (x2 - x1) * sx;
    int newY2 = y1 + (y2 - y1) * sy;

    drawRect(x1 + 300, y1, newX2 + 300, newY2, RED);
}

// Rotation
void rotateShape(int x1, int y1, int x2, int y2)
{
    float angle = 30;   // reduced angle for safety
    float rad = angle * 3.1416 / 180;

    int cx = (x1 + x2) / 2;
    int cy = (y1 + y2) / 2;

    int px[4] = {x1, x2, x2, x1};
    int py[4] = {y1, y1, y2, y2};

    int rx[4], ry[4];
    int i;

    for(i = 0; i < 4; i++)
    {
        rx[i] = cx + (px[i] - cx) * cos(rad) - (py[i] - cy) * sin(rad);
        ry[i] = cy + (px[i] - cx) * sin(rad) + (py[i] - cy) * cos(rad);
    }

    setcolor(YELLOW);

    for(i = 0; i < 4; i++)
    {
        line(rx[i] + 300, ry[i] + 180,
             rx[(i+1)%4] + 300, ry[(i+1)%4] + 180);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x1 = 80, y1 = 80, x2 = 160, y2 = 160;

    // ORIGINAL
    drawRect(x1, y1, x2, y2, WHITE);
    outtextxy(x1, y1 - 15, "Original");

    // TRANSLATION
    translate(x1, y1, x2, y2);
    outtextxy(x1 + 80, y1 + 165, "Translated");

    // SCALING
    scale(x1, y1, x2, y2);
    outtextxy(x1 + 300, y1 - 15, "Scaled");

    // ROTATION
    rotateShape(x1, y1, x2, y2);
    outtextxy(x1 + 300, y1 + 150, "Rotated");

    getch();
    closegraph();
    return 0;
}
