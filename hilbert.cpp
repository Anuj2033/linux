/*
Name:- DARSHAN MAYUR SHAH
Class:- SE COMP 2nd SHIFT
Sub:- Computer Graphics
Roll No-31
Exam Seat No-S150324244
ASSIGNMENT B17:-
Hilbert Curve
*/
#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

void move(int j, int h, int &x, int &y)
{
	if(j==1) 
		y-=h;
	else if(j==2)
		x+=h;
	else if(j==3)
		y+=h;
	else if(j==4)
		x-=h;
	lineto(x,y);
	delay(50);
}

void hilbert(int d, int r, int u, int l, int i, int h, int &x, int &y)
{
	if(i>0)
	{
		i--;
		hilbert(r,d,l,u,i,h,x,y);
		move(d,h,x,y);

		hilbert(d,r,u,l,i,h,x,y);
		move(r,h,x,y);
		
		hilbert(d,r,u,l,i,h,x,y);
		move(u,h,x,y);

		hilbert(l,u,r,d,i,h,x,y);
	}

}

int main()

{
	int n,x1,y1;
	int x0=50, y0=150, x, y, h=10, u=1, r=2, d=3, l=4;
	cout<<"\nGive the value of n: ";
	cin>>n;
	
	x=x0;
	y=y0;

	int gd=DETECT,gm=0;
	initgraph(&gd,&gm,NULL);

	moveto(x, y);
	hilbert(d, r, u, l, n, h, x, y);
	delay(5000);

	closegraph();
	return 0;
}
