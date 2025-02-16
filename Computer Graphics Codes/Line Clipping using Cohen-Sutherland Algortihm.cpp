#include <iostream>
#include <graphics.h>
using namespace std;

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

int computeCode(int x, int y, int xmin, int ymin, int xmax, int ymax) {
    int code = INSIDE;
    if (x < xmin) code |= LEFT;
    else if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    else if (y > ymax) code |= TOP;
    return code;
}

void drawColoredLine(int x1, int y1, int x2, int y2, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    setcolor(WHITE);
}

void cohenSutherland(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    int code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
    int code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);
    bool accept = false;
    drawColoredLine(x1, y1, x2, y2, RED);
    while (true) {
        if (!(code1 | code2)) {
            accept = true;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            int x, y;
            int codeOut = code1 ? code1 : code2;
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    }
    if (accept) {
        drawColoredLine(x1, y1, x2, y2, BLACK);
        drawColoredLine(x1, y1, x2, y2, GREEN);
    } else {
        drawColoredLine(x1, y1, x2, y2, BLACK);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int xmin = 100, ymin = 100, xmax = 400, ymax = 300;
    rectangle(xmin, ymin, xmax, ymax);
    cohenSutherland(50, 50, 300, 250, xmin, ymin, xmax, ymax);
    cohenSutherland(150, 150, 175, 50, xmin, ymin, xmax, ymax);
    cohenSutherland(200, 350, 100, 80, xmin, ymin, xmax, ymax);
    cohenSutherland(500, 450, 75, 90, xmin, ymin, xmax, ymax);
    getch();
    closegraph();
    return 0;
}
