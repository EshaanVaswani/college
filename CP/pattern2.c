#include<stdio.h>

int main(){
    printf("ESHAAN VASWANI D-34 \n\n");

    int i,j,k,l;

    for(i=1;i<=4;i++){
        for(j=1;j<=(4-i);j++){
            printf(" ");
        }
        for(k=i;k>=1;k--){
            printf("%d",k);
        }
        for(l=65;l<65+i-1;l++){
            printf("%c",l);
        }
        printf("\n");
    }

    return 0;
}
