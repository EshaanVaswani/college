import java.util.*;

public class BerkeleyClockSync {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("=== Berkeley Clock Synchronization ===");

        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();

        int[] clocks = new int[n];

        // Input clock times
        System.out.println("Enter clock times:");
        for (int i = 0; i < n; i++) {
            System.out.print("Process " + i + ": ");
            clocks[i] = sc.nextInt();
        }

        System.out.print("Enter master process ID: ");
        int master = sc.nextInt();

        System.out.println("\n--- Initial Clock Values ---");
        for (int i = 0; i < n; i++) {
            System.out.println("P" + i + " = " + clocks[i]);
        }

        // Step 1: Master collects all times
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += clocks[i];
        }

        int avg = sum / n;

        System.out.println("\nMaster (P" + master + ") calculates average = " + avg);

        // Step 2: Compute offsets
        int[] offset = new int[n];

        System.out.println("\n--- Offsets to adjust ---");
        for (int i = 0; i < n; i++) {
            offset[i] = avg - clocks[i];
            System.out.println("P" + i + " offset = " + offset[i]);
        }

        // Step 3: Apply adjustments
        System.out.println("\n--- Updated Clock Values ---");
        for (int i = 0; i < n; i++) {
            clocks[i] += offset[i];
            System.out.println("P" + i + " = " + clocks[i]);
        }

        sc.close();
    }
}