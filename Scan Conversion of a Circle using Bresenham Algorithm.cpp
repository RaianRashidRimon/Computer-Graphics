#include<stdio.h>
#include<graphics.h>
#include<math.h>
using namespace std;
int main()
{
    int r,x,y,d,dt,ds,h,k;
    printf("Enter the coordinates of the center: ");
    scanf("%d%d",&h,&k);
    printf("Enter the radius of the circle: ");
    scanf("%d",&r);
    x=0;
    y=r;
    d=3-2*r;
    initwindow(1000,600);
    while(x<=y)
    {
        putpixel(x+h,y+k,YELLOW);
        putpixel(y+h,x+k,YELLOW);
        putpixel(-y+h,x+k,YELLOW);
        putpixel(-x+h,y+k,YELLOW);
        putpixel(-x+h,-y+k,YELLOW);
        putpixel(-y+h,-x+k,YELLOW);
        putpixel(y+h,-x+k,YELLOW);
        putpixel(x+h,-y+k,YELLOW);
        if(d<0)
        {
            dt=4*x+6;
            d+=dt;
        }
        else
        {
            ds=4*(x-y)+10;
            d+=ds;
            y--;
        }
        x++;
    }
    getch();
    return 0;
}
