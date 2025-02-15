#include<iostream>
#include<graphics.h>
using namespace std;

void midpoint(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int p = 1-r;

    while(x<=y)
    {
        putpixel(xc+x,yc+y, CYAN);
        putpixel(xc-x,yc+y, CYAN);
        putpixel(xc+x,yc-y, CYAN);
        putpixel(xc-x,yc-y, CYAN);
        putpixel(xc+y,yc+x, CYAN);
        putpixel(xc-y,yc+x, CYAN);
        putpixel(xc+y,yc-x, CYAN);
        putpixel(xc-y,yc-x, CYAN);
        if(p<0)
        {
            p += 2*x+3;
        }
        else
        {
            p += 2*(x-y)+5;
            y--;
        }
        x++;
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm, "");
    int xc,yc,r;
    cout<<"Enter the center of the circle (x,y)"<<endl;
    cin >> xc >> yc;
    cout << "Enter the radius of the circle: " << endl;
    cin >> r;
    midpoint(xc,yc,r);
    delay(5000000);
    closegraph();
    return 0;
}
