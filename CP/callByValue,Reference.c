#include<stdio.h>

void swapbyval(int , int );
void swapbyref(int* ,int*);

int main(){

    printf("ESHAAN VASWANI D-34 \n\n");

    int a,b;

    printf("Enter the two numbers : ");
    scanf("%d%d",&a,&b);

    printf("ORIGINAL ORDER : ");
    printf("%d %d\n",a,b);

    swapbyval(a,b);
    printf("After swapping by value : ");
    printf("%d %d \n",a,b);

    swapbyref(&a,&b);
    printf("After swapping by reference : ");
    printf("%d %d\n",a,b);

    return 0;
}

void swapbyval(int a, int b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void swapbyref(int*a ,int*b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
