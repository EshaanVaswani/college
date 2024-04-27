#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main()
{
   int gd = DETECT, gm;
   int x, y, r, i, dp, n;
   clrscr();

   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

   printf("Eshaan Vaswani C33 181\n");

   printf("Enter number of concentric circles");

   scanf("%d", &n);
   for (i = 1; i <= n; i++)
   {
      printf("Enter radius of the circle %d:", i);
      scanf("%d", &r);
      x = 0;
      y = r;
      dp = 1 - r;

      while (y >= x)
      {
         putpixel(320 + x, 240 + y, 15);
         putpixel(320 + y, 240 + x, 15);
         putpixel(320 - y, 240 + x, 15);
         putpixel(320 - x, 240 + y, 15);
         putpixel(320 - x, 240 - y, 15);
         putpixel(320 - y, 240 - x, 15);
         putpixel(320 + y, 240 - x, 15);
         putpixel(320 + x, 240 - y, 15);
         if (dp < 0)
         {
            dp += (2 * x) + 1;
         }
         else
         {
            y = y - 1;
            dp += (2 * x) - (2 * y) + 1;
         }
         x += 1;
      }
      r = 0;
   }
   line(320, 0, 320, 480);
   line(0, 240, 640, 240);
   getch();
}