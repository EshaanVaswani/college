#include<stdio.h>

int fact(int);
int main(){
    printf("ESHAAN VASWANI D-34 \n\n");

    int n,r,ncr;
    printf("Enter n and r to calculate nCr :");
    scanf("%d%d",&n,&r);

    ncr=fact(n)/(fact(r)*fact(n-r));
    printf("%dC%d=%d",n,r,ncr);

    return 0;
}

int fact(int n){
    int i,f=1;

    if(n==0||n==1)
        return 1;
    else{
        for(i=1;i<=n;i++){
            f=f*i;
        }
    }

    return f;
}
