/* Experiment 9: Rainy Night Animation */

#include <graphics.h>
#include <conio.h>
#include <dos.h>

#define GROUND_Y 400
#define SKY_BOT 399

void drawBackground()
{
    // Evening sky
    setcolor(EGA_BLUE);
    setfillstyle(SOLID_FILL, EGA_BLUE);
    bar(0, 0, 639, SKY_BOT);

    // Moon
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    fillellipse(550, 60, 20, 20);

    // Clouds
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);

    // left cloud
    fillellipse(120, 80, 40, 18);
    fillellipse(150, 72, 35, 16);
    fillellipse(180, 82, 40, 18);

    // middle cloud
    fillellipse(280, 100, 45, 16);
    fillellipse(320, 92, 35, 14);

    // right cloud
    fillellipse(430, 85, 45, 18);
    fillellipse(470, 78, 35, 16);
    fillellipse(510, 88, 40, 18);

    // Road
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(0, GROUND_Y, 639, 479);

    setcolor(LIGHTGRAY);
    line(0, GROUND_Y, 639, GROUND_Y);
    line(0, 478, 639, 478);

    // Dashed lane divider
    setcolor(WHITE);
    {
        int i;
        for (i = 0; i < 640; i += 40)
            line(i, 440, i + 20, 440);
    }
}

void drawBuildings()
{
    int x, y;

    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);

    bar(40, 180, 90, 400);
    bar(120, 140, 190, 400);
    bar(240, 200, 300, 400);
    bar(350, 130, 430, 400);
    bar(500, 170, 580, 400);

    setcolor(YELLOW);

    for (x = 50; x < 80; x += 15)
        for (y = 200; y < 380; y += 25)
            rectangle(x, y, x + 8, y + 8);

    for (x = 130; x < 180; x += 15)
        for (y = 160; y < 380; y += 25)
            rectangle(x, y, x + 8, y + 8);

    for (x = 250; x < 290; x += 15)
        for (y = 220; y < 380; y += 25)
            rectangle(x, y, x + 8, y + 8);

    for (x = 360; x < 420; x += 15)
        for (y = 150; y < 380; y += 25)
            rectangle(x, y, x + 8, y + 8);

    for (x = 510; x < 570; x += 15)
        for (y = 190; y < 380; y += 25)
            rectangle(x, y, x + 8, y + 8);
}

void drawRain(int off, int manX)
{
    int i;

    int umbX = manX + 6;
    int umbY = 330 - 168;
    int radius = 42;

    setcolor(CYAN);

    for (i = 0; i < 120; i++)
    {
        int x = (i * 73 + off * 4) % 650;
        int y = (i * 47 + off * 6) % 310;

        int dx = x - umbX;
        int dy = y - umbY;

        int inside = (dx * dx + dy * dy < radius * radius && y >= umbY);

        if (inside)
            continue;

        line(x, y, x - 5, y + 14);
    }
}

void drawMan(int mx, int my, int legPhase)
{
    int ux = mx + 28;
    int uy = my - 35;

    // Umbrella handle
    setcolor(BROWN);
    line(mx + 12, my + 12, ux, uy + 10);

    // Umbrella canopy
    setcolor(MAGENTA);
    setfillstyle(SOLID_FILL, MAGENTA);
    pieslice(ux, uy, 0, 180, 35);

    // Umbrella ribs
    setcolor(BLACK);
    line(ux - 25, uy, ux - 15, uy + 10);
    line(ux, uy, ux, uy + 12);
    line(ux + 25, uy, ux + 15, uy + 10);

    // Head
    setcolor(WHITE);
    circle(mx, my - 15, 11);

    // Body
    line(mx, my - 4, mx, my + 32);

    // Arms
    line(mx, my + 8, mx - 15, my + 18);
    line(mx, my + 8, mx + 12, my + 12);

    // Legs
    if (legPhase == 0)
    {
        line(mx, my + 32, mx - 14, my + 58);
        line(mx, my + 32, mx + 8, my + 58);
    }
    else
    {
        line(mx, my + 32, mx - 8, my + 58);
        line(mx, my + 32, mx + 14, my + 58);
    }

    // Shoes
    line(mx - 18, my + 58, mx - 10, my + 58);
    line(mx + 4, my + 58, mx + 12, my + 58);
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int manX = 600;
    int manY = 342;
    int rainOff = 0;
    int legPhase = 0;
    int frame = 0;

    while (!kbhit())
    {
        cleardevice();

        drawBackground();
        drawBuildings();
        drawRain(rainOff, manX);
        drawMan(manX, manY, legPhase);

        manX -= 2;
        rainOff = (rainOff + 3) % (18 * 25);

        if (frame % 8 == 0)
            legPhase = 1 - legPhase;

        if (manX < -80)
            manX = 700;

        frame++;

        delay(35);
    }

    getch();
    closegraph();

    return 0;
}