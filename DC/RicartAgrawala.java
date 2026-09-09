import java.util.*;

class Process {
    int id;
    int timestamp;
    boolean requesting = false;
    int repliesNeeded;
    Queue<Integer> deferred = new LinkedList<>();

    Process(int id) {
        this.id = id;
    }
}

public class RicartAgrawala {

    static Process[] processes;
    static int n;

    public static void requestCS(int pid, int time) {
        Process p = processes[pid];
        p.requesting = true;
        p.timestamp = time;
        p.repliesNeeded = n - 1;

        System.out.println("\nProcess " + pid + " requests CS at time " + time);

        for (int i = 0; i < n; i++) {
            if (i == pid) continue;

            Process other = processes[i];

            if (!other.requesting ||
                (other.timestamp > p.timestamp) ||
                (other.timestamp == p.timestamp && other.id > pid)) {

                System.out.println("Process " + i + " sends OK to " + pid);
                p.repliesNeeded--;

            } else {
                System.out.println("Process " + i + " defers reply to " + pid);
                other.deferred.add(pid);
            }
        }

        checkEnterCS(pid);
    }

    public static void checkEnterCS(int pid) {
        Process p = processes[pid];

        if (p.requesting && p.repliesNeeded == 0) {
            enterCS(pid);
        }
    }

    public static void enterCS(int pid) {
        System.out.println("Process " + pid + " ENTERS Critical Section");
    }

    public static void releaseCS(int pid) {
        Process p = processes[pid];
        p.requesting = false;

        System.out.println("Process " + pid + " RELEASES Critical Section");

        while (!p.deferred.isEmpty()) {
            int req = p.deferred.poll();
            System.out.println("Process " + pid + " now sends deferred OK to " + req);

            processes[req].repliesNeeded--;

            checkEnterCS(req); // check if requester can now enter CS
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        n = sc.nextInt();

        processes = new Process[n];
        for (int i = 0; i < n; i++) {
            processes[i] = new Process(i);
        }

        System.out.print("Enter number of requests: ");
        int r = sc.nextInt();

        int[] pid = new int[r];
        int[] time = new int[r];

        System.out.println("Enter process ID and timestamp:");
        for (int i = 0; i < r; i++) {
            pid[i] = sc.nextInt();
            time[i] = sc.nextInt();
        }

        // Sort by (timestamp, process ID)
        Integer[] order = new Integer[r];
        for (int i = 0; i < r; i++) order[i] = i;

        Arrays.sort(order, (a, b) -> {
            if (time[a] != time[b])
                return time[a] - time[b];
            return pid[a] - pid[b];
        });

        System.out.println("\n--- Execution Order ---");

        for (int idx : order) {
            requestCS(pid[idx], time[idx]);
        }

        // NOW release in order
        System.out.println("\n--- Releasing Processes ---");

        for (int idx : order) {
            releaseCS(pid[idx]);
        }

        sc.close();
    }
}