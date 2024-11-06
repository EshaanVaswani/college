import java.io.*;
import java.net.*;
import java.util.*;

public class client {
   public static void main(String[] args) {
      try {
         Socket s = new Socket("localhost", 6666);
         Scanner sc = new Scanner(System.in);

         DataInputStream dis = new DataInputStream(s.getInputStream());
         DataOutputStream dout = new DataOutputStream(s.getOutputStream());

         System.out.println("Enter a number: ");
         int number = sc.nextInt();
         dout.writeInt(number);
         dout.flush();

         String serverRes = dis.readUTF();
         System.out.println("Server says: " + serverRes);

         if (serverRes.contains("Please send a message")) {
            sc.nextLine();
            System.out.println("Enter a message: ");
            String msg = sc.nextLine();
            dout.writeUTF(msg);
            dout.flush();
            String finalRes = dis.readUTF();
            System.out.println("Server says: " + finalRes);
         }
         dout.close();
         dis.close();
         sc.close();
         s.close();
      } catch (Exception e) {
         System.out.println(e);
      }
   }
}
