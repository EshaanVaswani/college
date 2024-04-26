import java.util.*;

class PayOutOfBounds extends Exception {
    public PayOutOfBounds(String message) {
        super(message);
    }
}

class Superintendent {
    public void processSalary(int basicPay) throws PayOutOfBounds {
        // Check if basic pay is out of bounds
        if (basicPay < 25000 || basicPay > 50000) {
            throw new PayOutOfBounds("Error: Basic pay is out of bounds (25,000 - 50,000).");
        } else {
            System.out.println("Salary processed successfully. Basic pay: " + basicPay);
        }
    }
}

public class CustomException2 {
    public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);
      System.out.println("Eshaan Vaswani C33 181 \n");

        Superintendent superintendent = new Superintendent();
        System.out.println("Enter basic pay:");
        int basicPay = scanner.nextInt(); 

        try {
            superintendent.processSalary(basicPay);
        } catch (PayOutOfBounds e) {
            System.out.println(e.getMessage());
        }
    }
}
