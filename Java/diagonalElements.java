import java.util.Scanner;

class diagonalElements {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);

        System.out.println("Eshaan Vaswani C33 181 \n");

        System.out.print("Enter the number of rows and columns: ");
        int rows = s.nextInt();
        int cols = s.nextInt();

        int[][] matrix = new int[rows][cols];

        // Input matrix elements
        System.out.println("Enter the elements of the matrix:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = s.nextInt();
            }
        }

        System.out.println("Matrix:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrix[i][j] + "\t");
            }
            System.out.println("");
        }

        if (isSquareMatrix(matrix)) {
            int diagonalSum = sumDiagonalElements(matrix);
            System.out.println("Sum of diagonal elements: " + diagonalSum);
        } else {
            System.out.println("The matrix is not a square matrix.");
        }

        s.close();
    }

    static boolean isSquareMatrix(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        return rows == cols;
    }

    static int sumDiagonalElements(int[][] a) {
        int sum = 0;
        int rows = a.length;

        for (int i = 0; i < rows; i++) {
            sum += a[i][i]; // Sum the elements on the main diagonal
        }

        return sum;
    }
}
