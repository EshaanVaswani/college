#include <stdio.h>
#define MAX 5

int stack[MAX], top;
top = -1;

void isFull()
{
      printf("Stack is full.Overflow condition.\n");
}

isEmpty()
{
      printf("Stack empty. Underflow condition.\n");
}

void push()
{
      if (top == MAX - 1)
      {
            isFull();
      }

      else
      {
            int element;
            printf("Enter element to be pushed ");
            scanf("%d", &element);
            top++;
            stack[top] = element;
            printf("%d element pushed in the stack.\n", element);
      }
}

void pop()
{
      if (top == -1)
            isEmpty();
      else
      {
            printf("The element popped from the stack is %d \n", stack[top]);
            top--;
      }
}

void peek()

{
      if (top == -1)
            isEmpty();

      else
      {

            printf("The element at the top is %d\n", stack[top]);
      }
}

void display()
{

      if (top == -1)
            isEmpty();

      else
      {
            int i = top;

            printf("Stack: ");
            for (i = top; i >= 0; i--)
            {
                  printf("\n%d", stack[i]);
            }
      }
}

void main()
{
      int choice;

      do
      {
            printf("\nEnter the operations to be performed ");
            printf("\n1.Push \n2.Pop \n3.Peek \n4.Display \n5.Exit");
            printf("\nEnter your choice ");
            scanf("%d", &choice);

            switch (choice)
            {

            case 1:
                  push();
                  break;

            case 2:
                  pop();
                  break;

            case 3:
                  peek();
                  break;

            case 4:
                  display();
                  break;
            }
      }
      while (choice != 5);
}
