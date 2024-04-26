import java.util.*;

class Student {
   String name;
   int[] marks = new int[3];
   int totalMarks = 0;
}

class studentResults {
   public static void main(String args[]) {
      System.out.println("Eshaan Vaswani C33 181 \n");

      Scanner sc = new Scanner(System.in);

      Student[] students = new Student[5];

      for (int i = 0; i < 5; i++) {
         students[i] = new Student();

         System.out.print("\nEnter name of student " + (i + 1) + ":");
         students[i].name = sc.nextLine();

         for (int j = 0; j < 3; j++) {
            System.out.print("Enter marks in subject " + (j + 1) + ":");
            students[i].marks[j] = sc.nextInt();
            students[i].totalMarks += students[i].marks[j];
         }

         sc.nextLine();
      }

      int highestMarks = 0;
      for (int i = 1; i < 5; i++) {
         if (students[i].totalMarks > students[highestMarks].totalMarks) {
            highestMarks = i;
         }
      }

      System.out.println("\nTotal marks of students:");
      for (int i = 0; i < 5; i++) {
         System.out.println(students[i].name + ":" + students[i].totalMarks);
      }

      System.out.println("\nStudent with highest total marks: " + students[highestMarks].name);
      System.out.println("Total Marks: " + students[highestMarks].totalMarks);

      sc.close();
   }
}