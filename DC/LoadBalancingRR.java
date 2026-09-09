import java.util.Scanner;

public class LoadBalancingRR {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of servers: ");
        int servers = sc.nextInt();

        System.out.print("Enter number of tasks: ");
        int tasks = sc.nextInt();

        int[] load = new int[servers];

        int currentServer = 0;

        System.out.println("\nTask Assignment:");

        for (int i = 1; i <= tasks; i++) {

            System.out.println("Task " + i + " assigned to Server " + currentServer);

            load[currentServer]++;

            currentServer = (currentServer + 1) % servers;
        }

        System.out.println("\nFinal Load on Servers:");

        for (int i = 0; i < servers; i++) {
            System.out.println("Server " + i + " handled " + load[i] + " tasks");
        }

        sc.close();
    }
}
