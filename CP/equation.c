#include<stdio.h>

void readMatrix(int[10][10],int,int);
void printMatrix(int[10][10],int,int);
void addMatrix(int[10][10],int[10][10],int[10][10],int,int);
void multiplyMatrix(int[10][10],int[10][10],int[10][10],int,int,int);

void main(){
    printf("ESHAAN VASWANI D-34 \n\n");

    int a[10][10],b[10][10],c[10][10],d[10][10],e[10][10],f[10][10],y[10][10];
    int a1,a2,b1,b2,c1,c2,d1,d2;

    printf("Enter size of matrix A:");
    scanf("%d%d",&a1,&a2);

    printf("Enter the elements of matrix A:");
    readMatrix(a,a1,a2);

    printf("Enter size of matrix B: ");
    scanf("%d%d",&b1,&b2);

    printf("Enter the elements of matrix B:");
    readMatrix(b,b1,b2);

    printf("Enter size of matrix C:");
    scanf("%d%d",&c1,&c2);

    printf("Enter the elements of matrix C:");
    readMatrix(c,c1,c2);

    printf("Enter size of matrix D:");
    scanf("%d%d",&d1,&d2);

    printf("Enter the elements of matrix D:");
    readMatrix(d,d1,d2);

    if(a1==b1&&a2==b2){
        addMatrix(a,b,e,a1,a2);
        printf("The addition of matrix A and B is: \n");
        printMatrix(e,a1,a2);
    }
    else{
        printf("Can't add matrix A and B!");
    }

    if(c2==d1){
        multiplyMatrix(c,d,f,c1,d2,c2);
        printf("The multiplication of matrix C and D is: \n");
        printMatrix(f,c1,d2);
    }
    else{
        printf("Can't multiply matrix C and D!");
    }

    if(a2==c1){
        multiplyMatrix(e,f,y,a1,d2,a2);
        printf("The value of Y is: \n");
        printMatrix(y,a1,d2);
    }
}

void readMatrix(int a[10][10],int m,int n){
    int i,j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d",&a[i][j]);
        }
    }
}

void printMatrix(int a[10][10],int m,int n){
    int i,j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("\t%d",a[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int a[10][10],int b[10][10],int c[10][10],int m,int n){
    int i,j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }
}

void multiplyMatrix(int a[10][10],int b[10][10],int c[10][10],int m,int n, int p){
    int i,j,k;

    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            c[i][j]=0;
            for(k=0; k<p; k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}
