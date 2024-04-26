#include<stdio.h>

int main(){
    printf("ESHAAN VASWANI D-34 \n\n");

    int i,j,k=0,c=0;
    char a[100];

    printf("Enter the string : ");
    gets(a);

    for(i=0;a[i]!='\0';i++){
        k++;
    }
    printf("The size of the string is %d \n",k);

    for(j=0;j<=k/2;j++){
        if(a[j]==a[k-1-j])
            c=1;
        else{
            c=0;
            break;
        }
    }

if(c==0)
    printf("It is not a palindrome");
else if(c==1)
    printf("It is a palindrome");

return 0;
}
