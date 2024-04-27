#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

void symmetrypts(int x, int y, int xc, int yc)
{
   putpixel(x + xc, y + yc, 15);
   putpixel(x + xc, -y + yc, 15);
   putpixel(-x + xc, -y + yc, 15);
   putpixel(-x + xc, y + yc, 15);
}

void main()
{
   int gd = DETECT, gm;
   long xc, yc, rx, ry, p1, p2, x, y;
   clrscr();

   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

   printf("Eshaan Vaswani C33 181\n");

   printf("Enter the coordinates of center:");
   scanf("%ld %ld", &xc, &yc);

   printf("Enter rx and ry:");
   scanf("%ld %ld", &rx, &ry);

   x = 0;
   y = ry;
   putpixel(x, y, 15);

   p1 = ry * ry - rx * rx + 0.25 * rx * rx; // initial parameter

   while (2 * ry * ry * x <= 2 * rx * rx * y)
   {
      if (p1 < 0)
      {
         x = x + 1;
         y = y;
         symmetrypts(x, y, xc, yc);
         p1 = p1 + 2 * ry * ry * x + ry * ry;
      }
      else
      {
         x += 1;
         y -= 1;
         symmetrypts(x, y, xc, yc);
         p1 = p1 + (2 * ry * ry * x) - (2 * rx * rx * y) + ry * ry;
      }
   }

   p2 = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y - 1) * (y - 1) - rx * rx * ry * ry;
   while (y > 0)
   {
      if (p2 < 0)
      {
         x += 1;
         y -= 1;
         symmetrypts(x, y, xc, yc);
         p2 = p2 + 2 * ry * ry * x - 2 * rx * rx * y + rx * rx;
      }
      else
      {
         x = x;
         y -= 1;
         symmetrypts(x, y, xc, yc);
         p2 = p2 - 2 * rx * rx * y + rx * rx;
      }
   }
   getch();
}