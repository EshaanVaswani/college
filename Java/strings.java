import java.util.*;

public class strings {
    public static void main(String[] args) {
      System.out.println("Eshaan Vaswani C33 181 \n");

        Scanner s = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String input = s.nextLine();

        int uppercaseCount = 0;
        int lowercaseCount = 0;
        int specialCharCount = 0;
        int spaceCount = 0;
        int digitCount = 0;

        for (int i = 0; i < input.length(); i++) {
            char ch = input.charAt(i);

            if (ch >= 'A' && ch <= 'Z') {
                uppercaseCount++;
            } else if (ch >= 'a' && ch <= 'z') {
                lowercaseCount++;
            } else if (ch >= '0' && ch <= '9') {
                digitCount++;
            } else if (ch == ' ') {
                spaceCount++;
            } else {
                specialCharCount++;
            }
        }

        System.out.println("Uppercase letters: " + uppercaseCount);
        System.out.println("Lowercase letters: " + lowercaseCount);
        System.out.println("Special characters: " + specialCharCount);
        System.out.println("Blank spaces: " + spaceCount);
        System.out.println("Digits: " + digitCount);

        s.close();
    }
}
