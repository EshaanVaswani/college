import java.util.*;

class Max {
    int a, b, c;

    Max(int n1, int n2, int n3) {
        a = n1;
        b = n2;
        c = n3;
    }

    int getMax() {
        int max = a > b ? (a > c ? a : c) : (b > c ? b : c);

        return max;
    }
}

class max3Nos {
    public static void main(String args[]) {
        System.out.println("Eshaan Vaswani C33 181 \n");

        Scanner s = new Scanner(System.in);
        System.out.println("Enter three numbers: ");
        Max obj = new Max(s.nextInt(), s.nextInt(), s.nextInt());
        int result = obj.getMax();
        System.out.println("Maximum = " + result);

        s.close();
    }

}
