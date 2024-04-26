#include <stdio.h>

int main() {
    int choice;
    float radius, length, width, base, height, area;
    char repeat;

    printf("ESHAAN VASWANI D-34 \n\n");
    do {
        printf("Choose a shape:\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Triangle\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the radius of the circle: ");
                scanf("%f", &radius);
                area = 3.14159 * radius * radius;
                printf("Area of the circle: %.2f\n", area);
                break;
            case 2:
                printf("Enter the length of the rectangle: ");
                scanf("%f", &length);
                printf("Enter the width of the rectangle: ");
                scanf("%f", &width);
                area = length * width;
                printf("Area of the rectangle: %.2f\n", area);
                break;
            case 3:
                printf("Enter the base of the triangle: ");
                scanf("%f", &base);
                printf("Enter the height of the triangle: ");
                scanf("%f", &height);
                area = (base * height) / 2;
                printf("Area of the triangle: %.2f\n", area);
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("Do you want to calculate the area of another shape? (Y/N): ");
        scanf(" %c", &repeat);
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}
