import java.io.*;

class Admission {
    
    public static void main(String args[]) throws IOException {
        System.out.println("Eshaan Vaswani C33 181 \n");

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);

        System.out.println("Enter marks in Mathematics: ");
        int m = Integer.parseInt(br.readLine());

        System.out.println("Enter marks in Physics: ");
        int p = Integer.parseInt(br.readLine());

        System.out.println("Enter marks in Chemistry: ");
        int c = Integer.parseInt(br.readLine());

        int t = p + c + m;

        if (m >= 60 && p >= 50 && c >= 40 && t >= 200){
            System.out.println("Congratulations! You are eligible for the admission.");
        } else {
            System.out.println("Oops! You are not eligible for the admission.");
        }
    }
}
