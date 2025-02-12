#include<stdio.h>
#include<graphics.h>
#include<math.h>
void bresenhamLine(double x1, double y1, double x2, double y2)
{
    int xp1,xp2,yp1,yp2,xp,yp,dx,dy,steps,i;
    double xi,yi,x,y;
    xp1=floor(x1+0.5);
    yp1=floor(y1+0.5);
    xp2=floor(x2+0.5);
    yp2=floor(y2+0.5);
    dx=xp2-xp1;
    dy=yp2-yp1;
    if(abs(dx)>abs(dy))steps=abs(dx);
    else steps=abs(dy);
    xi=dx/(double)steps;
    yi=dy/(double)steps;
    x=xp1;
    y=yp1;
    putpixel(xp1,yp1,YELLOW);
    for(i=0;i<steps;i++)
    {
        x+=xi;
        y+=yi;
        xp=floor(x+0.5);
        yp=floor(y+0.5);
        putpixel(xp,yp,YELLOW);
    }
}
int main()
{
    int gd=DETECT,gm;
    double xa=600,ya=150,xb=400,yb=50,xc=200,yc=150,xd=300,yd=300,xe=500,ye=300;
    initwindow(1000,600);
    bresenhamLine(xb,yb,xa,ya);
    bresenhamLine(xa,ya,xd,yd);
    bresenhamLine(xb,yb,xc,yc);
    bresenhamLine(xc,yc,xe,ye);
    bresenhamLine(xd,yd,xe,ye);
    bresenhamLine(xb,yb,400,250);
    bresenhamLine(xc,yc,xa,ya);
    getch();
    return 0;
}

