import java.util.*;

class evenOdd {
    static int even = 0;
    static int odd = 0;

    public static void main(String args[]) {
        System.out.println("Eshaan Vaswani C33 181 \n");

        Scanner s = new Scanner(System.in);

        System.out.println("Enter size of array: ");
        int size = s.nextInt();

        int a[] = new int[size];

        System.out.println("Enter elements: ");

        for (int i = 0; i < size; i++) {
            a[i] = s.nextInt();
        }

        for (int i = 0; i < size; i++) {
            if (a[i] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }

        System.out.println("No. of even elements = " + even);
        System.out.println("No. of odd elements = " + odd);

        s.close();
    }
}
