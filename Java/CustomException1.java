import java.util.Scanner;

// Custom Exception class
class InvalidNumberException extends Exception {
    public InvalidNumberException(String message) {
        super(message);
    }
}

public class CustomException1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Eshaan Vaswani C33 181 \n");

        System.out.print("Enter a number (5, 6, or 7): ");

        try {
            int number = scanner.nextInt();

            // Check if the entered number is 5, 6, or 7
            if (number != 5 && number != 6 && number != 7) {
                throw new InvalidNumberException("Invalid number entered!");
            }

            System.out.println("Entered number is: " + number);
        } catch (InvalidNumberException e) {
            System.out.println(e.getMessage());
        }

        scanner.close();
    }
}
