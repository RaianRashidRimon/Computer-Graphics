#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void drawBresenhamLine(int x1, int y1, int x2, int y2, int color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true)
    {
        putpixel(x1, y1, color);
        if (x1 == x2 && y1 == y2)
        {
            break;
        }
        int err2 = 2 * err;
        if (err2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}
int main()
{
    int x1 = 0, y1 = 0, x2, y2;
    cout << "Enter the coordinates of the ending point (X2 Y2): ";
    cin >> x2 >> y2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawBresenhamLine(x1, y1, x2, y2, WHITE);
    float angle = 30 * M_PI / 180;
    int x1_rotated = x1 * cos(angle) - y1 * sin(angle);
    int y1_rotated = x1 * sin(angle) + y1 * cos(angle);
    int x2_rotated = x2 * cos(angle) - y2 * sin(angle);
    int y2_rotated = x2 * sin(angle) + y2 * cos(angle);
    drawBresenhamLine(x1_rotated, y1_rotated, x2_rotated, y2_rotated, BLUE);
    int x1_scaled = x1 * 0.5;
    int y1_scaled = y1 * 0.5;
    int x2_scaled = x2 * 0.5;
    int y2_scaled = y2 * 0.5;
    drawBresenhamLine(x1_scaled, y1_scaled, x2_scaled, y2_scaled, RED);
    int x1_translated = x1 + 75;
    int y1_translated = y1;
    int x2_translated = x2 + 75;
    int y2_translated = y2;
    drawBresenhamLine(x1_translated, y1_translated, x2_translated, y2_translated, GREEN);
    getch();
    closegraph();
    return 0;
}
