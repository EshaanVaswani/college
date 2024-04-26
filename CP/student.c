#include<stdio.h>

struct marks{
    char name[100];
    int phy,chem,maths,rollno,total;
};

int main(){
    printf("ESHAAN VASWANI D-34 \n\n");
    struct marks s;

    printf("Enter the name of the student :");gets(s.name);
    printf("Enter the roll number : ");
    scanf("%d",&s.rollno);
    printf("Enter the marks in Physics, Chemistry and Mathematics :");
    scanf("%d%d%d",&s.phy,&s.chem,&s.maths);
    s.total=s.phy+s.chem+s.maths;

    printf("\n\nName\tRollNo\tTotal Marks\n");
    printf("%s\t%d\t%d\n",s.name,s.rollno,s.total);

    return 0;
}
