#include<stdio.h>
#include<graphics.h>
#include<math.h>
using namespace std;
int main()
{
    int xp1,xp2,yp1,yp2,xp,yp,dx,dy,steps,i;
    double x1,x2,y1,y2,xi,yi,x,y;
    printf("Enter the coordinates of the starting point of the line: ");
    scanf("%lf%lf",&x1,&y1);
    printf("Enter the coordinates of the ending point of the line: ");
    scanf("%lf%lf",&x2,&y2);
    xp1=floor(x1+0.5);
    yp1=floor(y1+0.5);
    xp2=floor(x2+0.5);
    yp2=floor(y2+0.5);
    dx=xp2-xp1;
    dy=yp2-yp1;
    if(abs(dx)>abs(dy))
        steps=abs(dx);
    else
        steps=abs(dy);
    xi=dx/(double)steps;
    yi=dy/(double)steps;
    x=xp1;
    y=yp1;
    initwindow(1000,600);
    putpixel(xp1,yp1,YELLOW);
    for(i=0; i<steps; i++)
    {
        x+=xi;
        y+=yi;
        xp=floor(x+0.5);
        yp=floor(y+0.5);
        putpixel(xp,yp,YELLOW);
    }
    getch();
    return 0;
}
