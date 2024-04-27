#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

int initializeDirectionOfx(int x1, int x2)
{
	int s1;

	if(x2 - x1 < 0)
		s1 = -1;

	else if(x2 - x1 > 0)
		s1 = 1;

	else
		s1 = 0;

	return s1;
}

int initializeDirectionOfy(int y1, int y2)
{
	int s2;

	if(y2 - y1 < 0)
		s2 = -1;

	else if(y2 - y1 > 0)
		s2 = 1;

	else
		s2 = 0;

	return s2;
}

void drawLineUsingGeneralisedBresenham(int x1, int y1, int x2, int y2)
{
    int x, y, dx, dy, s1, s2, P0, temp, i;
    int swap;

    x = x1;
    y = y1;

    putpixel(x, y, WHITE);

    swap = 0;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    s1 = initializeDirectionOfx(x1, x2);
    s2 = initializeDirectionOfy(y1, y2);

    if(dy > dx)
    {
	temp = dy;
	dy = dx;
	dx = temp;
	swap = 1;
    }

    P0 = 2 * dy - dx;

    for(i = 1; i <= dx; i++)
    {
	if(P0 < 0)
	{
		if(swap == 1)
		{
			x = x;
			y = y + s2;
			putpixel(x, y, WHITE);
		}

		else
		{
			x = x + s1;
			y = y;
			putpixel(x, y, WHITE);
		}

		P0 = P0 + 2 * dy;
	}

	else
	{
		x = x + s1;
		y = y + s2;
		putpixel(x, y, WHITE);
		P0 = P0 + 2 * dy - 2 * dx;
	}
    }
}

void main()
{
	int x1, y1, x2, y2, x, y;
	int gd = DETECT, gm;

	clrscr();
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	printf("Eshaan Vaswani C33 181\n");

	printf("\nEnter coordinates of point 1:");
	scanf("%d%d", &x1, &y1);

	printf("\nEnter coordinates of point 2:");
	scanf("%d%d", &x2, &y2);

	x = getmaxx();
	y = getmaxy();
	line(x/2, 0, x/2, y);
	line(0, y/2, x, y/2);

	drawLineUsingGeneralisedBresenham(320+x1, 240-y1, 320+x2, 240-y2);

	getch();
}