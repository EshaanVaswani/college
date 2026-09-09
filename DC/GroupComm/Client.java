import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Client {

    public static void main(String[] args) throws Exception {

        Socket socket = new Socket("localhost", 9999);
        System.out.println("[CLIENT] Connected to server at " + socket.getLocalAddress());

        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter your name: ");
        String name = sc.nextLine();
        System.out.println("[CLIENT] Joined as: " + name);

        // Thread to receive messages
        new Thread(() -> {
            try {
                String msg;
                while ((msg = in.readLine()) != null) {
                    System.out.println("[INCOMING] " + msg);
                }
            } catch (Exception e) {
            }
        }).start();

        // Send messages
        while (true) {
            System.out.print("[" + name + "] Message: ");
            String message = sc.nextLine();

            out.println(name + ": " + message);
            System.out.println("[SENT] " + name + ": " + message);

            if (message.equalsIgnoreCase("exit")) {
                System.out.println("[CLIENT] Disconnecting...");
                socket.close();
                break;
            }
        }

        sc.close();
    }
}