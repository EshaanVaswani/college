#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void boundaryFill(int x, int y, int fillColor, int boundaryColor){
	if(getpixel(x,y)!=boundaryColor && getpixel(x,y)!=fillColor){
		putpixel(x,y,fillColor);
		boundaryFill(x-1,y,fillColor,boundaryColor);
		boundaryFill(x+1,y,fillColor,boundaryColor);
		boundaryFill(x,y+1,fillColor,boundaryColor);
		boundaryFill(x,y-1,fillColor,boundaryColor);
	}
}

void main(){
	int gd=DETECT,gm;
	int fillColor = 5;
	int boundaryColor = 15;
	int x,y;
	int x1,y1,x2,y2;
	clrscr();

	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	printf("Eshaan Vaswani C33 181\n");

	printf("Enter window coordinates:\n");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

	printf("Enter coordinates of starting point:\n");
	scanf("%d%d",&x,&y);

	rectangle(x1,y1,x2,y2);

	boundaryFill(x,y,fillColor,boundaryColor);

	getch();
}