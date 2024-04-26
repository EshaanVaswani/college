#include<stdio.h>

int main(){
    printf("ESHAAN VASWANI D-34 \n\n");

    int n, n1, n2, digit, sum, i, d, p;

    printf("Armstrong numbers are.\n");
    for(n=100;n<=10000;n++){
        n1 = n2 = n;
        digit = 0;

        while(n1 != 0){
            digit++;
            n1 = n1 / 10;
        }

        sum = 0;

        while(n2 != 0){
            d = n2 % 10;
            p = 1;
            for(i = 1; i <= digit; i++){
                p = p * d;
            }
            sum = sum + p;
            n2 = n2 / 10;
        }

        if(sum == n)
            printf("%d\n", n);
    }

    return 0;
}
