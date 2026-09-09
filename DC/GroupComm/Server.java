
// Server.java
import java.io.*;
import java.net.*;
import java.util.*;

public class Server {

    // Thread-safe list for clients
    static List<ClientHandler> clients = Collections.synchronizedList(new ArrayList<>());

    public static void main(String[] args) throws Exception {

        ServerSocket serverSocket = new ServerSocket(9999);
        System.out.println("Group Communication Server started...");

        while (true) {
            Socket socket = serverSocket.accept();
            System.out.println("[SERVER] New client connected from " + socket.getInetAddress().getHostAddress() + ":"
                    + socket.getPort() + " | Total clients: " + (clients.size() + 1));

            ClientHandler client = new ClientHandler(socket);
            clients.add(client);
            client.start();
        }
    }

    // Broadcast message to all clients
    static void broadcast(String message) {
        synchronized (clients) {
            System.out.println("[BROADCAST] Broadcasting to " + clients.size() + " clients: " + message);
            for (ClientHandler client : clients) {
                client.send(message);
            }
        }
    }

    // Remove disconnected client
    static void removeClient(ClientHandler client) {
        clients.remove(client);
        System.out.println(
                "[SERVER] Client " + client.clientAddress + " disconnected | Remaining clients: " + clients.size());
    }

    static class ClientHandler extends Thread {
        Socket socket;
        BufferedReader in;
        PrintWriter out;
        String clientAddress;

        ClientHandler(Socket socket) throws Exception {
            this.socket = socket;
            this.clientAddress = socket.getInetAddress().getHostAddress() + ":" + socket.getPort();
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new PrintWriter(socket.getOutputStream(), true);
        }

        public void send(String message) {
            out.println(message);
        }

        public void run() {
            try {
                String msg;
                while ((msg = in.readLine()) != null) {

                    // Client wants to exit
                    if (msg.equalsIgnoreCase("exit")) {
                        System.out.println("[SERVER] Client " + clientAddress + " sent exit signal");
                        break;
                    }

                    System.out.println("[CLIENT " + clientAddress + "] Received: " + msg);
                    broadcast("[CLIENT] " + msg);
                }
            } catch (Exception e) {
                // Connection error
            } finally {
                removeClient(this);
                try {
                    socket.close();
                } catch (IOException e) {
                }
            }
        }
    }
}