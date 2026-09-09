import java.util.Scanner;

public class CMHDeadlock {

    static int n;
    static int[][] waitFor;

    static boolean probe(int initiator, int sender, int receiver) {

        System.out.println("Probe (" + initiator + ", " + sender + ", " + receiver + ")");

        // Deadlock detected
        if (receiver == initiator) {
            return true;
        }

        for (int i = 0; i < n; i++) {
            if (waitFor[receiver][i] == 1) {
                if (probe(initiator, receiver, i)) {
                    return true;
                }
            }
        }

        return false;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        n = sc.nextInt();

        waitFor = new int[n][n];

        System.out.println("Enter Wait-For Graph matrix:");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                waitFor[i][j] = sc.nextInt();
            }
        }

        System.out.print("Enter initiator process: ");
        int initiator = sc.nextInt();

        boolean deadlock = false;

        for (int i = 0; i < n; i++) {
            if (waitFor[initiator][i] == 1) {
                if (probe(initiator, initiator, i)) {
                    deadlock = true;
                    break;
                }
            }
        }

        if (deadlock)
            System.out.println("Deadlock detected using Chandy-Misra-Haas Algorithm");
        else
            System.out.println("No Deadlock detected");

        sc.close();
    }
}
