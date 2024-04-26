#include<stdio.h>

int main(){
  printf("ESHAAN VASWANI D-34 \n\n");
  int i, sum=0;

  for(i=5;i*(i+1)<400;i++){
    sum = sum + i;
  }

  printf(" The sum is %d",sum);

  return 0;
}
