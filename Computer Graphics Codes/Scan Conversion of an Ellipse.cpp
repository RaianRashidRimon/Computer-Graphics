#include<iostream>
#include<graphics.h>
using namespace std;
void drawellipse(int xc, int yc, int a, int b)
{
    int x=0;
    int y=b;
    int a_sqr = a*a;
    int b_sqr = b*b;
    int two_a_sqr = 2*a_sqr;
    int two_b_sqr = 2*b_sqr;
    int p;
    int px = 0;
    int py = two_a_sqr*y;
    p = b_sqr - (a_sqr*b)+(0.25*a_sqr);
    while(px<py)
    {
        putpixel(xc+x,yc+y, LIGHTCYAN);
        putpixel(xc-x,yc+y, LIGHTCYAN);
        putpixel(xc+x,yc-y, LIGHTCYAN);
        putpixel(xc-x,yc-y, LIGHTCYAN);
        x++;
        px += two_b_sqr;
        if(p<0)
        {
            p += b_sqr+px;
        }
        else
        {
            y--;
            py -= two_a_sqr;
            p += b_sqr + px-py;
        }
    }
    while(y>=0)
    {
        putpixel(xc+x,yc+y, LIGHTCYAN);
        putpixel(xc-x,yc+y, LIGHTCYAN);
        putpixel(xc+x,yc-y, LIGHTCYAN);
        putpixel(xc-x,yc-y, LIGHTCYAN);
        y--;
        py -= two_a_sqr;
        if(p>0)
        {
            p += a_sqr - py;
        }
        else
        {
            x++;
            px += two_a_sqr;
            p += a_sqr - py+px;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int xc,yc,a,b;
    cout << "Enter the center coordinate of the ellipse: " << endl;
    cin >> xc >> yc;
    cout << "Enter the length of the major axis: " << endl;
    cin >> a;
    cout <<"Enter the length of the minor axis: "<< endl;
    cin >> b;
    drawellipse(xc,yc,a,b);
    delay(500000);
    closegraph();
    return 0;
}
