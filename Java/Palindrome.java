import java.util.*;

class Palindrome {
   static boolean isPalindrome(String s) {
      int left = 0;
      int right = s.length() - 1;

      while (left < right) {
         if (s.charAt(left) != s.charAt(right)) {
            return false;
         }
         left++;
         right--;
      }
      return true;
   }

   public static void main(String args[]) {
      System.out.println("Eshaan Vaswani C33 181 \n");

      Scanner s = new Scanner(System.in);

      System.out.println("Enter a string: ");
      String str = s.nextLine();

      if (isPalindrome(str)) {
         System.out.println("The string is a palindrome.");
      } else {
         System.out.println("The string is not a palindrome.");
      }

      s.close();
   }
}
