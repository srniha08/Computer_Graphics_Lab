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
void translate(int x1, int y1, int x2, int y2, int tx, int ty)
{
    drawRect(x1 + tx, y1 + ty, x2 + tx, y2 + ty, GREEN);
}

// Scaling
void scale(int x1, int y1, int x2, int y2, float sx, float sy)
{
    int newX2 = x1 + (x2 - x1) * sx;
    int newY2 = y1 + (y2 - y1) * sy;

    drawRect(x1 + 300, y1, newX2 + 300, newY2, RED);
}

// Rotation
void rotateShape(int x1, int y1, int x2, int y2, float angle)
{
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

    int x1, y1, x2, y2;
    int tx, ty;
    float sx, sy, angle;

    // INPUT FROM USER
    printf("Enter x1 y1 x2 y2: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    printf("Enter translation (tx ty): ");
    scanf("%d %d", &tx, &ty);

    printf("Enter scaling (sx sy): ");
    scanf("%f %f", &sx, &sy);

    printf("Enter rotation angle: ");
    scanf("%f", &angle);

    cleardevice();

    // ORIGINAL
    drawRect(x1, y1, x2, y2, WHITE);
    outtextxy(x1, y1 - 15, "Original");

    // TRANSLATION
    translate(x1, y1, x2, y2, tx, ty);
    outtextxy(x1 + tx, y1 + ty - 15, "Translated");

    // SCALING
    scale(x1, y1, x2, y2, sx, sy);
    outtextxy(x1 + 300, y1 - 15, "Scaled");

    // ROTATION
    rotateShape(x1, y1, x2, y2, angle);
    outtextxy(x1 + 300, y1 + 150, "Rotated");

    getch();
    closegraph();
    return 0;
}
