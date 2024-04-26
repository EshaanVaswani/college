import java.util.*;

class Percentage {

    public static void main(String args[]) {
        System.out.println("Eshaan Vaswani C33 181 \n");

        char grade;
        Scanner input = new Scanner(System.in);

        System.out.println("Enter your grade: ");
        grade = input.next().charAt(0);

        switch (grade) {
            case 'A':
                System.out.println("Percentage Range: 91% to 100%");
                break;
            case 'B':
                System.out.println("Percentage Range: 81% to 90%");
                break;
            case 'C':
                System.out.println("Percentage Range: 71% to 80%");
                break;
            case 'D':
                System.out.println("Percentage Range: 61% to 70%");
                break;
            case 'F':
                System.out.println("Percentage Range: 0% to 60%");
                break;
        }

        input.close();
    }
}
