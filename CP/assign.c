#include <stdio.h>

void decimalToBinary(int num) {

    if (num == 0) {
      printf("0");
      return;
    }

   int binaryNum[32]; // Assuming 32 bit integer.
   int i=0;

   while (num > 0) {
      binaryNum[i++] = num % 2;
      num /= 2;
   }

   for (int j = i-1; j >= 0; j--)
      printf("%d", binaryNum[j]);
}
int main() {
   printf("ESHAAN VASWANI D-34 \n\n");
   int num ;
   printf("Enter the number you want to convert from decimal to binary : ");
   scanf("%d",&num);
   printf("BINARY : ");
   decimalToBinary(num);
   return 0;
}
