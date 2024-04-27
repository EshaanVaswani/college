#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void koch(int n, int x1, int y1, int x2, int y2)
{
    float angle = 60 * 3.14 / 180;
    int x3 = (2 * x1 + x2) / 3;
    int y3 = (2 * y1 + y2) / 3;
    int x4 = (x1 + 2.0 * x2) / 3;
    int y4 = (y1 + 2.0 * y2) / 3;
    int x = x3 + (x4 - x3) * cos(angle) + (y4 - y3) * sin(angle);
    int y = y3 - (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle);

    if(n > 0)
    {
	koch(n - 1, x1, y1, x3, y3);
	koch(n - 1, x3, y3, x, y);
	koch(n - 1, x, y, x4, y4);
	koch(n - 1, x4, y4, x2, y2);
    }

    else
    {
	line(x1, y1, x3, y3);
	line(x3, y3, x, y);
	line(x, y, x4, y4);
	line(x4, y4, x2, y2);

    }
}

void main()
{
	int n, i;
	double x1, y1, x2, y2;
	int gd = DETECT, gm;

	clrscr(); 

	initgraph(&gd, &gm, "..\\BGI");

	printf("Eshaan Vaswani C33 181\n");

	printf("\nEnter the number of iterations: ");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
		koch(n, 100, 100, 400, 400);

	getch();
}