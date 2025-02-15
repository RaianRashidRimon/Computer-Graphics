#include <iostream>
#include <graphics.h>

using namespace std;

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void magnifyTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int magnificationFactor) {
    int cx = 100;
    int cy = 100;
    x1 -= cx;
    y1 -= cy;
    x2 -= cx;
    y2 -= cy;
    x3 -= cx;
    y3 -= cy;
    x1 *= magnificationFactor;
    y1 *= magnificationFactor;
    x2 *= magnificationFactor;
    y2 *= magnificationFactor;
    x1 += cx;
    y1 += cy;
    x2 += cx;
    y2 += cy;
    drawTriangle(x1, y1, x2, y2, x3, y3);
}

int main() {
    int gd, gm;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "");
    cout << "The fixed point is (100,100)";
    cout <<"\n";
    int x1, y1, x2, y2;
    cout << "Enter coordinates of Point 2 (x2 y2): ";
    cin >> x1 >> y1;
    cout << "Enter coordinates of Point 3 (x3 y3): ";
    cin >> x2 >> y2;
    int x3 = 100;
    int y3 = 100;
    drawTriangle(x1, y1, x2, y2, x3, y3);
    int magnificationFactor;
    cout << "Enter magnification factor: ";
    cin >> magnificationFactor;
    magnifyTriangle(x1, y1, x2, y2, x3, y3, magnificationFactor);
    delay(5000000);
    closegraph();
    return 0;
}
