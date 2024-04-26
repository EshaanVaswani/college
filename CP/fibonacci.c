#include <stdio.h>
  int main() {
        int num, a = 0, b = 1, c, flag = 0;

        printf("ESHAAN VASWANI D-34 \n\n");

        printf("Enter a number:");
        scanf("%d", &num);

        if (num == a || num == b) {
                printf("%d is a fibonacci number\n", num);
                return 0;
        }

        while (b <= num) {
                c = b;
                b = a + b;
                a = c;
                if (b == num) {
                        flag = 1;
                        break;
                }
        }

        if (flag == 1) {
                printf("%d is a fibonacci number\n", num);
        }
        else {
                printf("%d is not a fibonacci number\n", num);
        }
        return 0;
  }
