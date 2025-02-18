#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
void drawRoad() {
    line(0, 400, 1000, 400);
}
void drawCar(int x, int y) {
    setfillstyle(SOLID_FILL,BLUE);
    bar(x, y, x + 80, y + 40);
    circle(x + 20, y + 40, 10);
    circle(x + 60, y + 40, 10);
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int maxX = getmaxx();
    int maxY = getmaxy();
    int carX = (maxX - 80) / 2;
    int carY = 360;
    int speed = 50;
    while (!kbhit()) {
        cleardevice();
        drawRoad();
        drawCar(carX, carY);
        carX += speed;
        if (carX > maxX + 80) {
            carX = -80;
        }
        delay(100);
    }
    closegraph();
    return 0;
}
