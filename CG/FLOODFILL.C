#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void floodFill(int x, int y, int fillColor, int interiorColor){
	if (getpixel(x,y)==interiorColor){
		putpixel(x,y,fillColor);

		floodFill(x-1,y,fillColor,interiorColor);
		floodFill(x+1,y,fillColor,interiorColor);
		floodFill(x,y+1,fillColor,interiorColor);
		floodFill(x,y-1,fillColor,interiorColor);
	}
}

void main(){
	int gd = DETECT,gm;
	int x,y;
	int x1,y1,x2,y2;
	int fillColor=4;
	int interiorColor=0;
	clrscr();

	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	printf("Eshaan Vaswani C33 181\n");

	printf("Enter window coordinates:\n");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

	printf("Enter coordinates of starting point:\n");
	scanf("%d%d",&x,&y);

	rectangle(x1,y1,x2,y2);

	floodFill(x,y,fillColor,interiorColor);

	getch();
}