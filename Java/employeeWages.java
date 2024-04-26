import java.util.*;

public class employeeWages {
    public static void main(String[] args) {
      System.out.println("Eshaan Vaswani C33 181 \n");

        Scanner s = new Scanner(System.in);

        int n = 5;
        String[] names = new String[n];
        int[] id = new int[n];
        int[] hrs = new int[n];
        int[] wages = new int[n];

        // Input details for each employee
        for (int i = 0; i < n; i++) {
            System.out.println("Enter details for Employee " + (i + 1) + ":");
            
            System.out.print("Name: ");
            names[i] = s.next();

            System.out.print("ID: ");
            id[i] = s.nextInt();

            System.out.print("Hours Worked: ");
            hrs[i] = s.nextInt();

            wages[i] = hrs[i] * 100; // Calculate wages (Rs. 100 per hour)
        }

        // Find the employee with the highest payment
        int highestPaymentIndex = 0;
        for (int i = 1; i < n; i++) {
            if (wages[i] > wages[highestPaymentIndex]) {
                highestPaymentIndex = i;
            }
        }

        // Display information in tabular form
        System.out.println("\nEmployee Details:");
        System.out.println("-----------------------------------------------------------");
        System.out.println("Name\tID\tHours\tWages");
        System.out.println("-----------------------------------------------------------");
        for (int i = 0; i < n; i++) {
            System.out.printf(names[i] + "\t" + id[i] + "\t" + hrs[i] + "\t" + wages[i] + "\n");
        }
        System.out.println("-----------------------------------------------------------");

        // Display the employee with the highest payment
        System.out.println("Employee with the Highest Payment:");
        System.out.println("Name: " + names[highestPaymentIndex]);
        System.out.println("ID: " + id[highestPaymentIndex]);
        System.out.println("Hours Worked: " + hrs[highestPaymentIndex]);
        System.out.println("Wages (Rs.): " + wages[highestPaymentIndex]);

        s.close();
    }
}
