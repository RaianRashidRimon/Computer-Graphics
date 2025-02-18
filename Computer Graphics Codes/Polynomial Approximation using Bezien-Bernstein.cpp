#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
using namespace std;

int binomialCoeff(int n, int k) {
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void drawBezierCurve(int px[], int py[], int n, int color) {
    double t, x, y;
    for (t = 0.0; t <= 1.0; t += 0.00001) {
        x = 0;
        y = 0;

        for (int i = 0; i <= n; i++) {
            double B = binomialCoeff(n, i) * pow(1 - t, n - i) * pow(t, i);
            x += px[i] * B;
            y += py[i] * B;
        }
        putpixel((int)x, (int)y, color);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int n;
    printf("Enter the number of control points: ");
    scanf("%d", &n);
    if (n < 2) {
        printf("At least 2 points are needed to draw a curve.\n");
        closegraph();
        return 0;
    }
    int px[n], py[n];
    printf("Enter %d control points (x y):\n", n);
    for (int i = 0; i < n; i++) {
        printf("Point %d: ", i + 1);
        scanf("%d %d", &px[i], &py[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        line(px[i], py[i], px[i + 1], py[i + 1]);
    }
    drawBezierCurve(px, py, n - 1, WHITE);
    getch();
    closegraph();
    return 0;
}
