import java.util.*;

class transpose {
    public static void main(String[] args) {
        System.out.println("Eshaan Vaswani C33 181 \n");

        Scanner s = new Scanner(System.in);

        System.out.print("Enter the number of rows: ");
        int rows = s.nextInt();

        System.out.print("Enter the number of columns: ");
        int columns = s.nextInt();

        int[][] matrix = new int[rows][columns];

        System.out.println("Enter the elements of the matrix:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[i][j] = s.nextInt();
            }
        }

        System.out.println("Original Matrix:");
        printMatrix(matrix);

        int[][] transposeMatrix = new int[columns][rows];

        // Transpose the matrix
        for (int i = 0; i < columns; i++) {
            for (int j = 0; j < rows; j++) {
                transposeMatrix[i][j] = matrix[j][i];
            }
        }

        System.out.println("Transpose Matrix:");
        printMatrix(transposeMatrix);

        s.close();
    }

    static void printMatrix(int[][] matrix) {
        int rows = matrix.length;
        int columns = matrix[0].length;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
