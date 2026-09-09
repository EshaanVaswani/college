import java.util.Scanner;

public class Bully {

    static int n;
    static int[] process; // 1 = active, 0 = crashed
    static int coordinator = -1;

    static void startElection(int initiator) {

        System.out.println("\nElection started by process " + initiator);
        boolean higherProcessExists = false;

        for (int i = initiator + 1; i < n; i++) {
            if (process[i] == 1) {
                System.out.println("Election message sent from " + initiator + " to " + i);
                System.out.println("Okay message from " + i);
                higherProcessExists = true;

                // Higher process takes over election
                startElection(i);
                return;
            }
        }

        // No higher active process replied
        if (!higherProcessExists) {
            coordinator = initiator;
            System.out.println("\nProcess " + initiator + " becomes Coordinator");
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        n = sc.nextInt();

        process = new int[n];

        // All processes active initially
        for (int i = 0; i < n; i++) {
            process[i] = 1;
        }

        System.out.print("Enter process ID that crashed: ");
        int crashed = sc.nextInt();
        process[crashed] = 0;
        System.out.println("Process " + crashed + " has crashed");

        System.out.print("Enter process ID that starts election: ");
        int initiator = sc.nextInt();

        startElection(initiator);

        System.out.println("\nFinal Coordinator is Process " + coordinator);

        // Broadcast coordinator message
        for (int i = 0; i < n; i++) {
            if (process[i] == 1 && i != coordinator) {
                System.out.println("Message to " + i + ": Coordinator is " + coordinator);
            }
        }

        sc.close();
    }
}