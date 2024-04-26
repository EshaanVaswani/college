import java.util.*;

class Employee {

    String name;
    int empID;
    String dep;
    String pos;

    void readDetails() {
        Scanner s = new Scanner(System.in);

        System.out.println("Enter employee name: ");
        name = s.nextLine();

        System.out.println("Enter employee ID: ");
        empID = s.nextInt();
        s.nextLine();

        System.out.println("Enter employee department: ");
        dep = s.nextLine();

        System.out.println("Enter employee position: ");
        pos = s.nextLine();

        s.close();
    }

    void printDetails() {
        System.out.println("\nEmployee Details: ");
        System.out.println("Name: " + name);
        System.out.println("Employee ID: " + empID);
        System.out.println("Department: " + dep);
        System.out.println("Position: " + pos);
    }

    public static void main(String args[]) {
        System.out.println("Eshaan Vaswani C33 181 \n");
        Employee e = new Employee();
        e.readDetails();
        e.printDetails();
    }
}
