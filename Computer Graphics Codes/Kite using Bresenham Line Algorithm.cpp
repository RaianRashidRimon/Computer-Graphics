#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

void bresenhamLine(int x1, int y1, int x2, int y2, int color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    while (1) {
        putpixel(x1, y1, color);
        if (x1 == x2 && y1 == y2)
            break;
        int err2 = 2 * err;
        if (err2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}
int main() {
    int gd = DETECT, gm;
    initwindow(1000, 600);
    int xa = 600, ya = 150;
    int xb = 400, yb = 50;
    int xc = 200, yc = 150;
    int xd = 300, yd = 300;
    int xe = 500, ye = 300;
    bresenhamLine(xb, yb, xa, ya, RED);
    bresenhamLine(xa, ya, xd, yd, RED);
    bresenhamLine(xb, yb, xc, yc, RED);
    bresenhamLine(xc, yc, xe, ye, RED);
    bresenhamLine(xd, yd, xe, ye, RED);
    bresenhamLine(xc, yc, xa, ya, RED);
    getch();
    closegraph();
    return 0;
}
