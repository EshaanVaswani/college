import java.util.*;

class Marks {

    void totalMarks(int x[]) {
        int sum = 0;
        for (int i = 0; i < x.length; i++) {
            sum = sum + x[i];
        }
        System.out.println("Total Marks = " + sum);
    }

    void highestMarks(int x[]) {
        int max = x[0];
        for (int i = 0; i < x.length; i++) {
            if (x[i] > max) {
                max = x[i];
            }
        }
        System.out.println("Highest Marks = " + max);
    }
}

class studentMarks {
    public static void main(String args[]) {
        System.out.println("Eshaan Vaswani C33 181 \n");

        Scanner s = new Scanner(System.in);

        System.out.println("Enter no. of subjects: ");
        int sub = s.nextInt();

        int[] marks = new int[sub];

        System.out.println("Enter marks: ");
        for (int i = 0; i < sub; i++) {
            marks[i] = s.nextInt();
        }

        Marks m = new Marks();
        m.totalMarks(marks);
        m.highestMarks(marks);

        s.close();
    }
}
