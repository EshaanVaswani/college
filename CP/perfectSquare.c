#include <stdio.h>
#include <math.h>

int main(){
    printf("ESHAAN VASWANI D-34 \n\n");

    int n;
    double x;

    printf("Enter a 4-digit number:");
    scanf("%d",&n);

    x = 0;
    x = sqrt( (double)n );


    if(n==x*x)
        printf("%d is a Perfect Square\n\n",n);
    else
        printf("%d is NOT a Perfect Square\n\n",n);

    return 0;
}
