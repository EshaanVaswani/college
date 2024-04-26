#include<stdio.h>

int main(){
    printf("ESHAAN VASWANI D-34 \n\n");

    int n,i,search,k=0,location;

    printf("Enter the size of the array:");
    scanf("%d",&n);

    int a[n];
    printf("Enter the elements of the array:\n");

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("Enter the element you want to search in the array : ");
    scanf("%d",&search);

    for(i=0;i<n;i++){
        if(search==a[i]){
            k=1;
            location=i+1;
            break;
        }
    }

    if(k==1)
        printf("%d is present in the array at %d position\n",search,location);
    else
        printf("the element you have entered does not exists in the array\n");

    return 0;
}
