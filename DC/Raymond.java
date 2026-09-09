import java.util.*;

public class Raymond {

    static int n = 7;

    static int[] parent = { -1, -1, 1, 1, 2, 2, 3 };

    static int tokenHolder = 1;

    static Queue<Integer>[] requestQueue;
    static boolean[] requesting;

    static void printTree() {
        System.out.println("\nCurrent Tree Structure (Child -> Parent):");

        for (int i = 1; i < n; i++) {
            System.out.println("P" + i + " -> P" + parent[i]);
        }

        System.out.println("Token Holder: P" + tokenHolder);
    }

    static void requestCS(int process) {
        System.out.println("\nProcess " + process + " requests Critical Section");

        requesting[process] = true;

        int p = process;

        // forward request up the tree
        while (p != tokenHolder) {
            int par = parent[p];

            System.out.println("Request forwarded from P" + p + " to P" + par);
            requestQueue[par].add(p);

            p = par;
        }

        printTree();

        assignToken();
    }

    static void assignToken() {

        while (!requestQueue[tokenHolder].isEmpty()) {

            int next = requestQueue[tokenHolder].poll();

            System.out.println("Token passed from P" + tokenHolder + " to P" + next);

            int old = tokenHolder;
            tokenHolder = next;

            // update tree direction
            parent[old] = tokenHolder;
            parent[tokenHolder] = -1;

            printTree();

            if (requesting[tokenHolder]) {
                enterCS(tokenHolder);
                return;
            }
        }
    }

    static void enterCS(int process) {
        System.out.println("Process " + process + " ENTERS Critical Section");

        releaseCS(process);
    }

    static void releaseCS(int process) {
        System.out.println("Process " + process + " RELEASES Critical Section");

        requesting[process] = false;

        assignToken(); // serve next pending request
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        requestQueue = new LinkedList[n];
        requesting = new boolean[n];

        for (int i = 0; i < n; i++) {
            requestQueue[i] = new LinkedList<>();
        }

        System.out.print("Enter number of requests: ");
        int r = sc.nextInt();

        System.out.println("Enter requesting processes:");

        for (int i = 0; i < r; i++) {
            int req = sc.nextInt();
            requestCS(req); // 🔥 process one-by-one
        }

        System.out.println("\nFinal Token Holder: " + tokenHolder);

        sc.close();
    }
}