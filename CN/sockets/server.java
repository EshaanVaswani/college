import java.io.*;
import java.net.*;

public class server {
   public static void main(String[] args) {
      try {
         ServerSocket ss = new ServerSocket(6666);
         System.out.println("Server is waiting for the client request...");
         Socket s = ss.accept();
         System.out.println("Client connected!!");
         DataInputStream dis = new DataInputStream(s.getInputStream());
         DataOutputStream dout = new DataOutputStream(s.getOutputStream());

         int number = dis.readInt();
         System.out.println("Client sent the number: " + number);

         if (number % 2 == 0) {
            dout.writeUTF("The number is even. Please send a message");
            System.out.println("The number is even");
            dout.flush();
            String clientMsg = dis.readUTF();
            System.out.println("Client says: " + clientMsg);
            dout.writeUTF("Message received:" + clientMsg);
         } else {
            dout.writeUTF("The number is odd. Closing the connection...");
         }

         dis.close();
         dout.close();
         s.close();
         ss.close();
      } catch (Exception e) {
         System.out.println(e);
      }
   }
}
