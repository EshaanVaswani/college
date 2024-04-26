#include<stdio.h>

int main(){

    printf("ESHAAN VASWANI D-34 \n\n");

    int k=0,i;
    char a[100];

    printf("Enter the string : ");
    gets(a);

    for(i=0;a[i]!='\0';i++){
        if (a[i]=='a'|| a[i]=='A'|| a[i]=='e'|| a[i]=='E'|| a[i]=='i'|| a[i]=='I'|| a[i]=='o'|| a[i]=='O'|| a[i]=='u'|| a[i]=='U')
            k++;
    }

    printf("The number of vowels in the string is %d",k);

    return 0;
}
