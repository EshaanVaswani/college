#include <stdio.h>

void readMatrix(int matrix[][100], int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void addMatrices(int matrix1[][100], int matrix2[][100], int result[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[][100], int matrix2[][100], int result[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[][100], int matrix2[][100], int result[][100], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[][100], int rows, int cols) {
    printf("Resultant matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("ESHAAN VASWANI D-34 \n\n");

    int matrix1[100][100], matrix2[100][100], result[100][100];
    int choice, rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for the first matrix:\n");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the number of rows and columns for the second matrix:\n");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    printf("Menu:\n");
    printf("1. Add matrices\n");
    printf("2. Subtract matrices\n");
    printf("3. Multiply matrices\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (rows1 != rows2 || cols1 != cols2) {
                printf("Matrix addition is not possible.\n");
                return 0;
            }
            readMatrix(matrix1, rows1, cols1);
            readMatrix(matrix2, rows2, cols2);
            addMatrices(matrix1, matrix2, result, rows1, cols1);
            displayMatrix(result, rows1, cols1);
            break;
        case 2:
            if (rows1 != rows2 || cols1 != cols2) {
                printf("Matrix subtraction is not possible.\n");
                return 0;
            }
            readMatrix(matrix1, rows1, cols1);
            readMatrix(matrix2, rows2, cols2);
            subtractMatrices(matrix1, matrix2, result, rows1, cols1);
            displayMatrix(result, rows1, cols1);
            break;
        case 3:
            readMatrix(matrix1, rows1, cols1);
            readMatrix(matrix2, rows2, cols2);
            multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);
            displayMatrix(result, rows1, cols2);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
