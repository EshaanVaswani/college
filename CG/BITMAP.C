#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main()
{
   int i, j, x, y;
   int gd = DETECT, gm;
   int e[10][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    {1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
		    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

   printf("Eshaan Vaswani C33 181\n");

   for (i = 0; i < 10; i++)
   {
      for (j = 0; j < 10; j++)
      {
	 if (e[i][j] == 1)
	 {
	    putpixel(320 + j, 240 + i, WHITE);
	 }
      }
   }

   getch();
}
