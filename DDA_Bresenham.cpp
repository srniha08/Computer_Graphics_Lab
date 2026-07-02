#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

void DDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xinc = dx / (float)steps;
    float yinc = dy / (float)steps;
    float x = x1, y = y1;

    for(int i = 0; i <= steps; i++) {
        putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);
        x += xinc;
        y += yinc;
    }
}

void Bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    int x = x1, y = y1;
    while(1) {
        putpixel(x, y, YELLOW);
        if(x == x2 && y == y2) break;
        int e2 = 2 * err;
        if(e2 > -dy) { err -= dy; x += sx; }
        if(e2 < dx) { err += dx; y += sy; }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    DDA(100, 100, 400, 200);
    Bresenham(100, 300, 400, 400);

    setcolor(WHITE);
    outtextxy(150, 50, "DDA Line");
    setcolor(YELLOW);
    outtextxy(150, 250, "Bresenham Line");

    getch();
    closegraph();
    return 0;
}
