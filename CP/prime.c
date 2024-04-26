#include<stdio.h>

int main() {
  printf("ESHAAN VASWANI D-34 \n\n");
  int n,i;

  printf("Prime no.s between 50 and 150 are:\n");
  for(n=50;n<=150;n++){
    for(i=2;i<= n-1;i++){
      if(n%i==0)
        break;
    }
    if(i==n){
      printf("%d \n",n);
    }
  }

  return 0;
}
