#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void grid()
{

	line(0, 240, 640, 240);
	line(320, 0, 320, 480);
}

void draw(int c00, int c01, int c10, int c11, int c20, int c21)
{

	line(320 + c00, 240 - c01, 320 + c10, 240 - c11);
	line(320 + c00, 240 - c01, 320 + c20, 240 - c21);
	line(320 + c10, 240 - c11, 320 + c20, 240 - c21);
}

void matrixMulti(double a[10][10], double b[10][10], double c[10][10], int m, int n, int p)
{

	int i, j, k;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < p; j++)
		{
			c[i][j] = 0;
			for (k = 0; k < n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

void addElements(double a[10][10], double num1, double num2, double num3, double num4, double num5, double num6, double num7, double num8, double num9)
{
	a[0][0] = num1;
	a[0][1] = num2;
	a[0][2] = num3;
	a[1][0] = num4;
	a[1][1] = num5;
	a[1][2] = num6;
	a[2][0] = num7;
	a[2][1] = num8;
	a[2][2] = num9;
}

void main()
{
	int gd = DETECT, gm;
	int x1, y1, x2, y2, x3, y3, tx, ty, theta, ch, rot1, rot2, sx, sy, sc1, sc2, slope, c, r1, r2, sh;
	double thetaRad = 0, thetaRef = 0;
	double mat1[10][10], mat2[10][10], result1[10][10], result2[10][10];

	clrscr();

	printf("Enter the coordinates of triangle....\n");
	printf("Point 1: ");
	scanf("%d%d", &x1, &y1);
	printf("Point 2: ");
	scanf("%d%d", &x2, &y2);
	printf("Point 3: ");
	scanf("%d%d", &x3, &y3);

	do
	{
		printf("Eshaan Vaswani C33 181\n");
		printf("******************MENU******************\n");
		printf("1. Translation\n2. Rotation about origin\n3. Rotation about a fixed point\n4. Scaling about origin\n5. Scaling about a fixed point\n6. Reflection about x-axis\n7. Reflection about y-axis\n8. Reflection about origin\n9. Reflection about any line y = mx + c\n10. Shearing in x-direction\n11. Shearing in y-direction\n12. Exit\n");

		printf("\nEnter your choice: ");
		scanf("%d", &ch);

		if (ch == 1)
		{
			printf("Enter the translation coordinates: ");
			scanf("%d%d", &tx, &ty);

			initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

			grid();

			draw(x1, y1, x2, y2, x3, y3);

			addElements(mat1, x1, x2, x3, y1, y2, y3, 1, 1, 1);

			addElements(mat2, 1, 0, tx, 0, 1, ty, 0, 0, 1);

			matrixMulti(mat2, mat1, result1, 3, 3, 3);

			delay(2000);

			setcolor(14);

			draw((int)result1[0][0], (int)result1[1][0], (int)result1[0][1], (int)result1[1][1], (int)result1[0][2], (int)result1[1][2]);

			getch();
			closegraph();
		}

		else if (ch == 2)
		{
			printf("Enter the angle (in degrees) by which you want to rotate the triangle: ");
			scanf("%d", &theta);

			thetaRad = (double)theta * 3.14 / 180.0;

			initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

			grid();

			draw(x1, y1, x2, y2, x3, y3);

			addElements(mat1, cos(thetaRad), -sin(thetaRad), 0, sin(thetaRad), cos(thetaRad), 0, 0, 0, 1);

			addElements(mat2, x1, x2, x3, y1, y2, y3, 1, 1, 1);

			matrixMulti(mat1, mat2, result1, 3, 3, 3);

			delay(2000);

			setcolor(14);

			draw((int)result1[0][0], (int)result1[1][0], (int)result1[0][1], (int)result1[1][1], (int)result1[0][2], (int)result1[1][2]);

			getch();
			closegraph();
		}

		else if (ch == 3)
		{
			printf("Enter the coordinates of the point about which you want to rotate the triangle: ");
			scanf("%d%d", &rot1, &rot2);

			printf("Enter the angle (in degrees) by which you want to rotate the triangle: ");
			scanf("%d", &theta);

			thetaRad = (double)theta * 3.14 / 180.0;

			initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

			grid();

			draw(x1, y1, x2, y2, x3, y3);

			addElements(mat1, x1, x2, x3, y1, y2, y3, 1, 1, 1);

			addElements(mat2, 1, 0, -rot1, 0, 1, -rot2, 0, 0, 1);

			matrixMulti(mat2, mat1, result1, 3, 3, 3);

			addElements(mat1, cos(thetaRad), -sin(thetaRad), 0, sin(thetaRad), cos(thetaRad), 0, 0, 0, 1);

			addElements(mat2, result1[0][0], result1[0][1], result1[0][2], result1[1][0], result1[1][1], result1[1][2], 1, 1, 1);

			matrixMulti(mat1, mat2, result2, 3, 3, 3);

			addElements(mat1, 1, 0, rot1, 0, 1, rot2, 0, 0, 1);

			addElements(mat2, result2[0][0], result2[0][1], result2[0][2], result2[1][0], result2[1][1], result2[1][2], 1, 1, 1);

			matrixMulti(mat1, mat2, result1, 3, 3, 3);

			delay(2000);

			setcolor(14);

			draw((int)result1[0][0], (int)result1[1][0], (int)result1[0][1], (int)result1[1][1], (int)result1[0][2], (int)result1[1][2]);

			getch();
			closegraph();
		}

		else if (ch == 4)
		{

			printf("Enter the scaling factors: ");
			scanf("%d%d", &sx, &sy);

			initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

			grid();

			draw(x1, y1, x2, y2, x3, y3);

			addElements(mat1, sx, 0, 0, 0, sy, 0, 0, 0, 1);

			addElements(mat2, x1, x2, x3, y1, y2, y3, 1, 1, 1);

			matrixMulti(mat1, mat2, result1, 3, 3, 3);

			delay(2000);

			setcolor(14);

			draw((int)result1[0][0], (int)result1[1][0], (int)result1[0][1], (int)result1[1][1], (int)result1[0][2], (int)result1[1][2]);

			getch();
			closegraph();
		}

		else if (ch == 5)
		{

			printf("Enter the coordinates of the point about which you want to scale the triangle: ");
			scanf("%d%d", &sc1, &sc2);

			printf("Enter the scaling factors: ");
			scanf("%d%d", &sx, &sy);

			initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

			grid();

			draw(x1, y1, x2, y2, x3, y3);

			addElements(mat1, x1, x2, x3, y1, y2, y3, 1, 1, 1);

			addElements(mat2, 1, 0, -sc1, 0, 1, -sc2, 0, 0, 1);

			matrixMulti(mat2, mat1, result1, 3, 3, 3);

			addElements(mat1, sx, 0, 0, 0, sy, 0, 0, 0, 1);

			addElements(mat2, result1[0][0], result1[0][1], result1[0][2], result1[1][0], result1[1][1], result1[1][2], 1, 1, 1);

			matrixMulti(mat1, mat2, result2, 3, 3, 3);

			addElements(mat1, 1, 0, sc1, 0, 1, sc2, 0, 0, 1);

			addElements(mat2, result2[0][0], result2[0][1], result2[0][2], result2[1][0], result2[1][1], result2[1][2], 1, 1, 1);

			matrixMulti(mat1, mat2, result1, 3, 3, 3);

			delay(2000);

			setcolor(14);

			draw((int)result1[0][0], (int)result1[1][0], (int)result1[0][1], (int)result1[1][1], (int)result1[0][2], (int)result1[1][2]);

			getch();
			closegraph();
		}

		else if (ch == 6)
		{

			initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

			grid();

			draw(x1, y1, x2, y2, x3, y3);

			addElements(mat1, 1, 0, 0, 0, -1, 0, 0, 0, 1);

			addElements(mat2, x1, x2, x3, y1, y2, y3, 1, 1, 1);

			matrixMulti(mat1, mat2, result1, 3, 3, 3);

			delay(2000);

			setcolor(14);

			draw((int)result1[0][0], (int)result1[1][0], (int)result1[0][1], (int)result1[1][1], (int)result1[0][2], (int)result1[1][2]);

			getch();
			closegraph();
		}

		else if (ch == 7)
		{

			initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

			grid();

			draw(x1, y1, x2, y2, x3, y3);

			addElements(mat1, -1, 0, 0, 0, 1, 0, 0, 0, 1);

			addElements(mat2, x1, x2, x3, y1, y2, y3, 1, 1, 1);

			matrixMulti(mat1, mat2, result1, 3, 3, 3);

			delay(2000);

			setcolor(14);

			draw((int)result1[0][0], (int)result1[1][0], (int)result1[0][1], (int)result1[1][1], (int)result1[0][2], (int)result1[1][2]);

			getch();
			closegraph();
		}

		else if (ch == 8)
		{

			initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

			grid();

			draw(x1, y1, x2, y2, x3, y3);

			addElements(mat1, -1, 0, 0, 0, -1, 0, 0, 0, 1);

			addElements(mat2, x1, x2, x3, y1, y2, y3, 1, 1, 1);

			matrixMulti(mat1, mat2, result1, 3, 3, 3);

			delay(2000);

			setcolor(14);

			draw((int)result1[0][0], (int)result1[1][0], (int)result1[0][1], (int)result1[1][1], (int)result1[0][2], (int)result1[1][2]);

			getch();
			closegraph();
		}

		else if (ch == 9)
		{

			printf("Enter the values of m and c respectively: ");
			scanf("%d%d", &slope, &c);

			thetaRef = atan((double)slope) * 180.0 / 3.14;

			initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

			grid();

			draw(x1, y1, x2, y2, x3, y3);

			// delay(1500);

			// setcolor(14);

			// r1 = slope * 320 + c;
			// r2 = slope * (-320) + c;

			// line(640, 240-r1, 0, 240-r2);

			addElements(mat1, 1, 0, 0, 0, 1, -c, 0, 0, 1);

			addElements(mat2, x1, x2, x3, y1, y2, y3, 1, 1, 1);

			matrixMulti(mat1, mat2, result1, 3, 3, 3); // translate by (0,-c)

			addElements(mat1, cos(thetaRef), sin(thetaRef), 0, -sin(thetaRef), cos(thetaRef), 0, 0, 0, 1);

			addElements(mat2, result1[0][0], result1[0][1], result1[0][2], result1[1][0], result1[1][1], result1[1][2], 1, 1, 1);

			matrixMulti(mat1, mat2, result2, 3, 3, 3); // rotate by -thetaRef

			addElements(mat1, 1, 0, 0, 0, -1, 0, 0, 0, 1);

			addElements(mat2, result2[0][0], result2[0][1], result2[0][2], result2[1][0], result2[1][1], result2[1][2], 1, 1, 1);

			matrixMulti(mat1, mat2, result1, 3, 3, 3); // reflection done

			addElements(mat1, cos(thetaRef), -sin(thetaRef), 0, sin(thetaRef), cos(thetaRef), 0, 0, 0, 1);

			addElements(mat2, result1[0][0], result1[0][1], result1[0][2], result1[1][0], result1[1][1], result1[1][2], 1, 1, 1);

			matrixMulti(mat1, mat2, result2, 3, 3, 3);

			addElements(mat1, 1, 0, 0, 0, 1, c, 0, 0, 1);

			addElements(mat2, result2[0][0], result2[0][1], result2[0][2], result2[1][0], result2[1][1], result2[1][2], 1, 1, 1);

			matrixMulti(mat1, mat2, result1, 3, 3, 3);

			delay(2000);

			setcolor(14);

			draw((int)result1[0][0], (int)result1[1][0], (int)result1[0][1], (int)result1[1][1], (int)result1[0][2], (int)result1[1][2]);

			getch();
			closegraph();
		}

		else if (ch == 10)
		{

			printf("Enter the shearing parameter: ");
			scanf("%d", &sh);

			initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

			grid();

			draw(x1, y1, x2, y2, x3, y3);

			addElements(mat1, 1, sh, 0, 0, 1, 0, 0, 0, 1);

			addElements(mat2, x1, x2, x3, y1, y2, y3, 1, 1, 1);

			matrixMulti(mat1, mat2, result1, 3, 3, 3);

			delay(2000);

			setcolor(14);

			draw((int)result1[0][0], (int)result1[1][0], (int)result1[0][1], (int)result1[1][1], (int)result1[0][2], (int)result1[1][2]);

			getch();
			closegraph();
		}

		else if (ch == 11)
		{

			printf("Enter the shearing parameter: ");
			scanf("%d", &sh);

			initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

			grid();

			draw(x1, y1, x2, y2, x3, y3);

			addElements(mat1, 1, 0, 0, sh, 1, 0, 0, 0, 1);

			addElements(mat2, x1, x2, x3, y1, y2, y3, 1, 1, 1);

			matrixMulti(mat1, mat2, result1, 3, 3, 3);

			delay(2000);

			setcolor(14);

			draw((int)result1[0][0], (int)result1[1][0], (int)result1[0][1], (int)result1[1][1], (int)result1[0][2], (int)result1[1][2]);

			getch();
			closegraph();
		}

		else if (ch == 12)
		{
			printf("Exiting the program...\n");
		}

		else
		{
			printf("Invalid input....try again\n");
		}

	} while (ch != 12);
}