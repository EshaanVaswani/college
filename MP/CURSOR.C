#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
    int choice=1,count=1;
    while(1)
    {
	printf("\n\nEnter choice:");
	printf("\n1.Increement Cursor Size");
	printf("\n2.Decreement Cursor size");
	printf("\n3.Disable Cursor");
	printf("\n4.Exit");
	printf("\nEnter your choice: ");
	scanf("%d",&choice);

	switch(choice)
	{
	    case 1:

		 count++;
		 asm mov cx,count;
		 asm mov ah,01h;
		 asm INT 10h;

		 break;

	    case 2:
		count--;
		asm mov cx,count;
		asm mov ah,01h;
		asm INT 10h;
		break;

	    case 3:
		asm mov cl,20h;
		asm mov ah,01h;
		asm INT 10h;
		break;

	    case 4:
		printf("Exiting.....");
		exit(0);

	    default: printf("\nEnter a valid choice! ");
	    }
	}

	getch();
}