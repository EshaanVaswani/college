import java.util.Scanner;

class Staff {

  int code;
  String name;
  private String address;

  Staff(int code, String name) {

    this.code = code;
    this.name = name;
  }

  void setAddress(String address) {

    this.address = address;

  }

  void display() {
    System.out.println("ID Code: " + code);
    System.out.println("Your Name: " + name);
    System.out.println("Your address: " + address);

  }

}

class Teacher extends Staff {

  String subject;
  String Class;

  Teacher(int code, String name, String address, String subject, String Class) {

    super(code, name);

    this.setAddress(address);

    this.subject = subject;
    this.Class = Class;

  }

  void display() {
    super.display();
    System.out.println("Your Subject: " + subject);
    System.out.println("Your class: " + Class);

  }

}

class Officer extends Staff {

  String Grade;

  Officer(int code, String name, String address, String Grade) {

    super(code, name);

    this.setAddress(address);

    this.Grade = Grade;

  }

  void display() {
    super.display();
    System.out.println("Your Grade: " + Grade);

  }

}

class Typist extends Staff {

  int speed;

  Typist(int code, String name, String address, int speed) {

    super(code, name);

    this.setAddress(address);

    this.speed = speed;

  }

  void display() {
    super.display();
    System.out.println("Your Speed: " + speed);

  }

}

class Regular extends Typist {

  int Basicpay;

  Regular(int code, String name, String address, int speed, int Basicpay) {

    super(code, name, address, speed);

    this.Basicpay = Basicpay;

  }

  void display() {
    super.display();
    System.out.println("Your Baseic pay: " + Basicpay);

  }

}

class AdHoc extends Typist {

  int Basicpay;

  AdHoc(int code, String name, String address, int speed, int Basicpay) {

    super(code, name, address, speed);

    this.Basicpay = Basicpay;

  }

  void display() {
    super.display();
    System.out.println("Your Baseic pay: " + Basicpay);

  }

}

class Inheritance {

  public static void main(String args[]) {

    System.out.println("Eshaan Vaswani C33 181 \n");

    String role, name, address, subject, Class, grade, type;
    int speed, basePay, code;

    Scanner sc = new Scanner(System.in);

    do {
      System.out.println("Who is signing up.\n1.Teacher\n2.Officer\n3.Typist\nIf you want to exit enter exit");
      System.out.println("Enter your Role: ");

      role = sc.nextLine();

      System.out.println("Enter your ID Code: ");
      code = sc.nextInt();
      sc.nextLine();

      System.out.println("Enter your  name : ");
      name = sc.nextLine();

      System.out.println("Enter your address: ");
      address = sc.nextLine();

      if (role.equalsIgnoreCase("Teacher")) {

        System.out.println("Enter subject: ");
        subject = sc.nextLine();

        System.out.println("Enter Class: ");
        Class = sc.nextLine();

        Teacher t = new Teacher(code, name, address, subject, Class);

        t.display();

      }

      if (role.equalsIgnoreCase("Officer")) {

        System.out.println("Enter Grade: ");
        grade = sc.nextLine();

        Officer o = new Officer(code, name, address, grade);

        o.display();

      }

      if (role.equalsIgnoreCase("Typist")) {

        System.out.print("Specify your speed: ");
        speed = sc.nextInt();
        sc.next();

        System.out.print("Specify type\n1.Regular\n2.Add-hoc\n type: ");
        type = sc.next();

        System.out.println("Enter basic pay: ");
        basePay = sc.nextInt();
        sc.next();

        if (type.equalsIgnoreCase("Regular")) {

          Regular r = new Regular(code, name, address, speed, basePay);
          r.display();

        }

        else {

          AdHoc h = new AdHoc(code, name, address, speed, basePay);
          h.display();

        }

      }

      

    } while (role.equalsIgnoreCase("Exit"));

  }

}
