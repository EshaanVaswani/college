#include <stdio.h>

int main() {
  printf("ESHAAN VASWANI D-34\n\n");

  int i, j, row, col, a[5][5], sumrow, sumcol;

  printf("Enter the size of the matrix :\n ");
  scanf("%d%d", &row, &col);
  printf("\n");
  printf("Enter the elements of the matrix :\n");
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("\n");

  printf("The sum of each row of the matrix is : \n");
  for (i = 0; i < row; i++) {
    sumrow = 0;
    for (j = 0; j < col; j++) {
      sumrow += a[i][j];
    }
    printf("%d \n", sumrow);
  }

  printf("\n");

  printf("The sum of each column of the matrix is : \n");

  for (i = 0; i < row; i++) {
    sumcol = 0;
    for (j = 0; j < col; j++) {
      sumcol += a[j][i];
    }
    printf("%d \n", sumcol);
  }

  return 0;
}
