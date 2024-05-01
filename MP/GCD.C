#include<stdio.h>
#include<conio.h>
int main(){
  int a,b,res;
  clrscr();
  printf("Enter the first Number");
  scanf("%d",&a);
  printf("Enter the second number");
  scanf("%d",&b);
  asm mov ax,a
  asm mov bx,b
  bck:
  asm cmp ax,bx
  asm jc second
  first:
  asm sub ax,bx
  asm jmp chk
  second:
  asm sub bx,ax
  chk:
  asm cmp ax,bx
  asm jnz bck
  asm mov res,ax
  printf("The gcd is %d ",res);
  getch();
  }
