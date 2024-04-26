#include<stdio.h>

int main(){
    printf("ESHAAN VASWANI D-34 \n\n");

    int n,i,j,k;
    n=7;

    printf("A Diamond pattern of stars with a maximum number of %d stars in a line is :\n",n);

    for(i=1;i<=(n+1)/2;i++){
        for(j=1;j<=(((n+1)/2)-i);j++){
            printf(" ");
        }
        for(k=1;k<=(2*i-1);k++){
            printf("*");
        }
        printf("\n");
    }

    for(i=1;i<=(n-1)/2;i++){
        for(j=1;j<=i;j++){
            printf(" ");
        }
        for(k=1;k<=(n-(2*i));k++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
