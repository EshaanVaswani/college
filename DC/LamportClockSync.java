import java.util.Scanner;

// Lamport's Logical Clock Synchronization Example
public class LamportClockSync {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int clock1 = 0;
        int clock2 = 5;

        System.out.println("Process 1 initial time: " + clock1);
        System.out.println("Process 2 initial time: " + clock2);

        while (true) {

            System.out.println("\nEnter action (send / exit): ");
            String choice = sc.next();

            if (choice.equals("exit")) {
                break;
            }

            clock1++;
            System.out.println("Process 1 sent packet at time: " + clock1);

            clock2 = Math.max(clock2, clock1) + 1;
            System.out.println("Process 2 received packet at time: " + clock2);

            clock2++;
            System.out.println("Process 2 sent packet at time: " + clock2);

            clock1 = Math.max(clock1, clock2) + 1;
            System.out.println("Process 1 received packet at time: " + clock1);
        }

        sc.close();
    }
}