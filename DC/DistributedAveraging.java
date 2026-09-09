import java.util.Scanner;
import java.util.Random;

public class DistributedAveraging {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Random rand = new Random();

        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();

        double[] values = new double[n];
        double sum = 0;

        System.out.println("Enter initial values:");
        for (int i = 0; i < n; i++) {
            values[i] = sc.nextDouble();
            sum += values[i];
        }

        double actualAvg = sum / n;
        System.out.println("\nActual Global Average = " + actualAvg);

        System.out.print("Enter max number of iterations: ");
        int maxIterations = sc.nextInt();

        double epsilon = 0.001; // convergence threshold

        for (int it = 1; it <= maxIterations; it++) {

            // pick two random processes
            int i = rand.nextInt(n);
            int j = rand.nextInt(n);

            while (i == j) {
                j = rand.nextInt(n);
            }

            // averaging step
            double avg = (values[i] + values[j]) / 2;
            values[i] = avg;
            values[j] = avg;

            // print current state
            System.out.println("\nIteration " + it + ":");
            for (int k = 0; k < n; k++) {
                System.out.print("P" + k + "=" + String.format("%.4f", values[k]) + "  ");
            }

            // check convergence
            double max = values[0], min = values[0];
            for (double v : values) {
                if (v > max) max = v;
                if (v < min) min = v;
            }

            if (max - min < epsilon) {
                System.out.println("\n\nConverged after " + it + " iterations.");
                break;
            }
        }

        // final values
        System.out.println("\nFinal Values:");
        for (int i = 0; i < n; i++) {
            System.out.println("P" + i + " = " + String.format("%.4f", values[i]));
        }

        sc.close();
    }
}