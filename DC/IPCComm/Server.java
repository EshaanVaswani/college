import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) throws Exception {

        ServerSocket serverSocket = new ServerSocket(9999);
        System.out.println("Server is running...");

        Socket socket = serverSocket.accept();
        System.out.println("Client connected");

        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

        String message;

        while (true) {
            message = in.readLine();
            
            if (message == null || message.equalsIgnoreCase("exit")) {
                System.out.println("Client disconnected");
                break;
            }

            System.out.println("Received from client: " + message);

            out.println("Server: " + message);
        }

        socket.close();
        serverSocket.close();
    }
}