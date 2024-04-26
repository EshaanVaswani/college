import java.util.*;

import calci.*;

class PackageDemo {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Eshaan Vaswani C33 181 \n");

        System.out.println("Enter num1:");
        int n1 = sc.nextInt();

        System.out.println("Enter num2:");
        int n2 = sc.nextInt();

        System.out.println("1. Addition");
        System.out.println("2. Subtraction");
        System.out.println("3. Multiplication");
        System.out.println("4. Division");
        System.out.println("5. Exit");

        int c, result;

        do{
            System.out.println("Enter choice: ");
            c = sc.nextInt();        
        
            switch(c){
                case 1:
                    Addition a = new Addition(n1,n2);
                    result = a.add();
        
                    System.out.println("Addition = " + result);
                    break;
        
                case 2:
                    Subtraction s = new Subtraction(n1,n2);
                    result = s.subtract();
        
                    System.out.println("Subtraction = " + result);
                    break;
    
                case 3:
                    Multiplication m = new Multiplication(n1,n2);
                    result = m.multiply();

                    System.out.println("Multiplication = " + result);
                    break;

                case 4:
                    Division d = new Division(n1,n2);
                    result = d.divide();
    
                    System.out.println("Division = " + result);
                    break;    

                default:
                    System.out.println("Invalid choice!");
           }
        } while(c<5);
    }
}
