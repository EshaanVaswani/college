import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws Exception {

        Socket socket = new Socket("localhost", 9999);
        System.out.println("Connected to server");

        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

        Scanner sc = new Scanner(System.in);
        String message;

        while (true) {
            System.out.print("Enter msg for server: ");
            message = sc.nextLine();

            out.println(message);

            if (message.equalsIgnoreCase("exit"))
                break;

            String reply = in.readLine();
            System.out.println("Server: " + reply);
        }

        sc.close();
        socket.close();
    }
}