#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

void DDA(int x1, int y1, int x2, int y2, int ch){
	int dx, dy, s, i, x, y;
	int xi,yi;
	dx = x2 - x1;
	dy = y2 - y1;

	if (abs(dx) > abs(dy))
		s = abs(dx);
	else
		s = abs(dy);

	xi = dx / s;
	yi = dy / s;

	for (i = 1; i <= s; i++) {
		while(1){
		switch (ch) {
			case 1:
				putpixel(x1, y1, WHITE);
				x1 = x1 + (int)xi;
				y1 = y1 + (int)yi;
				break;
			case 2:
				putpixel(x1, y1, WHITE);
				putpixel(x1, y1 - 1, WHITE);
				putpixel(x1, y1 + 1, WHITE);
				x1 = x1 + (int)xi;
				y1 = y1 + (int)yi;
				break;
			case 3:
				if (i % 2 == 0){
					putpixel(x1, y1, WHITE);
				}
				x1 = x1 + (int)xi;
				y1 = y1 + (int)yi;
				break;
			case 4:
				if (i % 10 != 0) {
					putpixel(x1, y1, WHITE);
				}
				x1 = x1 + (int)xi;
				y1 = y1 + (int)yi;
				break;
			default:
				printf("Invalid choice");
		}
		}
	}
}

int main() {
	int x1, x2, y1, y2, x, y, c;
	int gd = DETECT, gm;

	clrscr();

	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	printf("Eshaan Vaswani C33 181\n");

	printf("Enter the co-ordinates x1 and y1:\n");
	scanf("%d%d", &x1, &y1);
	printf("Enter the co-ordinates x2 and y2:\n");
	scanf("%d%d", &x2, &y2);

	x = getmaxx();
	y = getmaxy();

	printf("\nEnter choice:\n1.Normal Line\n2.Thick Line\n3.Dotted Line\n4.Dash Line\n");
	scanf("%d", &c);

	DDA(320+x1, 240-y1, 320+x2, 240-y2, c);
	line(x / 2, 0, x / 2, y);
	line(0, y / 2, x, y / 2);

	getch();
	return 0;
}
