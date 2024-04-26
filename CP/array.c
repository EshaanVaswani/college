#include<stdio.h>

int main(){
    printf("ESHAAN VASWANI D-34 \n\n");

    int n,i,small,large;

    printf("Enter the size of the array:");
    scanf("%d",&n);

    int a[n];
    printf("Enter the elements of the array:\n");

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    small=a[0];
    large=a[0];

    for(i=0;i<n;i++){
        if(small>a[i])
            small= a[i];
        if(large<a[i])
            large= a[i];
    }

    printf("The largest number in the array is %d \n",large);
    printf("The smallest number in the array is %d \n",small);

    return 0;
}
