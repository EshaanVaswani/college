import java.util.Scanner;

class Shape {
   
    protected double area;

    public Shape() {
        area = 0.0;
    }

    public Shape(double area) {
        this.area = area;
    }

    public double calculateArea() {
        return area;
    }
}

class Square extends Shape {
    private double side;

    public Square(double side) {
        super(side * side);
        this.side = side;
    }
}

class Rectangle extends Shape {
    private double length;
    private double width;

    public Rectangle(double length, double width) {
        super(length * width);
        this.length = length;
        this.width = width;
    }
}

class Circle extends Shape {
    private double radius;

    public Circle(double radius) {
        super(Math.PI * radius * radius);
        this.radius = radius;
    }
}

public class constructorOL {
    public static void main(String[] args) {
      System.out.println("Eshaan Vaswani C33 181 \n");

        Scanner scanner = new Scanner(System.in);

        System.out.println("Choose a shape to calculate its area:");
        System.out.println("1. Square");
        System.out.println("2. Rectangle");
        System.out.println("3. Circle\n");
        int choice = scanner.nextInt();

        double area = 0.0;

        switch (choice) {
            case 1:
                System.out.print("Enter the side length of the square: ");
                double side = scanner.nextDouble();
                Square square = new Square(side);
                area = square.calculateArea();
                break;
            case 2:
                System.out.print("Enter the length of the rectangle: ");
                double length = scanner.nextDouble();
                System.out.print("Enter the width of the rectangle: ");
                double width = scanner.nextDouble();
                Rectangle rectangle = new Rectangle(length, width);
                area = rectangle.calculateArea();
                break;
            case 3:
                System.out.print("Enter the radius of the circle: ");
                double radius = scanner.nextDouble();
                Circle circle = new Circle(radius);
                area = circle.calculateArea();
                break;
            default:
                System.out.println("Invalid choice.");
        }

        System.out.println("Area: " + area);

        scanner.close();
    }
}

