#include<iostream>
#include <graphics.h>
using namespace std;

void floodFill(int x, int y, int fillColor, int oldColor) {
    if (getpixel(x, y) == oldColor) {
        putpixel(x, y, fillColor);
        floodFill(x + 1, y, fillColor, oldColor);
        floodFill(x - 1, y, fillColor, oldColor);
        floodFill(x, y + 1, fillColor, oldColor);
        floodFill(x, y - 1, fillColor, oldColor);
        floodFill(x + 1, y + 1, fillColor, oldColor);
        floodFill(x + 1, y - 1, fillColor, oldColor);
        floodFill(x - 1, y + 1, fillColor, oldColor);
        floodFill(x - 1, y - 1, fillColor, oldColor);
    }
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    rectangle(250,250,450,350);
    rectangle(300,300,550,400);
    int x = 275;
    int y = 260;
    int fill_color = LIGHTBLUE;
    int oldcolor= BLACK;
    floodFill(x,y,fill_color,oldcolor);
    getch();
    delay(500000);
    closegraph();
    return 0;
}
