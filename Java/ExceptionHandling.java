import java.util.*;

public class ExceptionHandling {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Eshaan Vaswani C33 181 \n");

        try {
            // Exception 1
            System.out.print("Enter 2 numbers: ");
            int num1 = scanner.nextInt();
            int num2 = scanner.nextInt();
            int result = num1 / num2;
            System.out.println(num1 + " / " + num2 + " = " + result);

            // Exception 2
            System.out.println("Enter no. of elements:");
            int size = scanner.nextInt();
            int[] array = new int[3];
            System.out.println("Enter elements of array:");
            for (int i = 0; i < size; i++){
               array[i] = scanner.nextInt();
            }

            // Exception 3
            String str = "abc";
            int value = Integer.parseInt(str);
        } catch (ArithmeticException e) {
            System.out.println("Error: Cannot divide by zero.");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: Array index out of bounds.");
        } catch (NumberFormatException e) {
            System.out.println("Error: Invalid number format.");
        }
    }
}
