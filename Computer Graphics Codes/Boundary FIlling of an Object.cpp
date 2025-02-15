#include<iostream>
#include<graphics.h>
using namespace std;

void boundaryFill(int x, int y, int fill_color, int boundary_color) {
    if (getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color) {
        putpixel(x, y, fill_color);
        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);
    }
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    rectangle(250,250,450,350);
    rectangle(300,300,550,400);
    int x = 275;
    int y = 260;
    int fill_color = YELLOW;
    int boundary_color = WHITE;
    boundaryFill(x, y, fill_color, boundary_color);
    delay(100000);
    closegraph();
    return 0;
}

