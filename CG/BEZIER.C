#include<stdio.h>
#include<conio.h>
#include <graphics.h>
#include <math.h>

void drawBezierCurve(int x[], int y[]) {
    float t, dt;
    int steps=1000;
    int i,px, py;

    for (i = 0; i <= steps; i++) {
	t = i/(float)steps;
	dt = 1 - t;

	px = dt * dt * dt * x[0] + 3 * dt * dt * t * x[1] + 3 * dt * t * t * x[2] + t * t * t * x[3];
	py = dt * dt * dt * y[0] + 3 * dt * dt * t * y[1] + 3 * dt * t * t * y[2] + t * t * t * y[3];

	putpixel(px, py, WHITE);
    }
}
void main() {
    int x[4],y[4],i;
    int gd = DETECT, gm;
    clrscr();

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    printf("Eshaan Vaswani C33 181\n");

    for(i=0; i<4; i++){
	printf("Enter coordinates of control point %d:",i);
	scanf("%d%d", &x[i],&y[i]);
    }

    drawBezierCurve(x, y);

    getch();
}
