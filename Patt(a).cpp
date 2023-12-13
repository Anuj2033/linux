
//317.5,235
#include <graphics.h>
#include <iostream>
using namespace std;

void dda(float x1,float y1,float x2,float y2)
{
	float xinc,yinc,x,y,dx,dy,len;
	int i;
		
	dx = (x2-x1);
	dy = (y2-y1);
	
	if (dx > dy)
	{
		len = abs(dx);
	}
	else
	{
		len = abs(dy);
	}
	
	x = x1;
	y = y1;
	
	xinc = dx/len;
	yinc = dy/len;
	
	for (i=0; i <= len; ++i)
	{
		putpixel(round(x), round(y), 3);
		x = x + xinc;
		y = y + yinc;
		
	}
	
	
}


void bca(int p, int q, int r)
{
	int d, x, y;
	
	x = 0;
	y = r;
	
	d = 3-(2*r);
	
	do
	{
		putpixel ((p + x), (q - y), 110);
		putpixel ((p - x), (q - y), 110);
        putpixel ((p - x), (q + y), 110);
        putpixel ((p + x), (q + y), 110);
        
        putpixel ((p + y), (q + x), 110);
		putpixel ((p + y), (q - x), 110);
        putpixel ((p - y), (q + x), 110);
        putpixel ((p - y), (q - x), 110);
        
		if (d < 0)
		{
			d = d + 4*x + 6;
		}
		else
		{
			d = d + 4*(x - y) + 10;
			y = y - 1;
		}
		
		x = x + 1;
	}while(x < y);
	
}


int main()
{	
	float p, q, r;
	int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL);
    
    cout<<"Enter center x coordinate:\n";
    cin>>p;
    cout<<endl<<"Enter center y coordinate:\n";
    cin>>q;
    cout<<endl<<"Enter radius:\n";
    cin>>r;
    
	dda(p, q - r, (p - (0.865*r)), q + (r/2));
	dda(p , q - r, (p + (0.865*r)), q + (r/2));
	dda((p - (0.865*r)), q + (r/2), (p + (0.865*r)), q + (r/2));
	bca(p, q, r);
	bca(p, q, r/2);
	delay(5000);
	
	closegraph();
	return 0;


}
