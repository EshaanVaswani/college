#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int rollNumber;
    int physicsMarks;
    int chemistryMarks;
    int mathematicsMarks;
    int totalMarks;
};

int main() {
    printf("ESHAAN VASWANI D-34 \n\n");

    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter the name: ");
        scanf("%s", students[i].name);

        printf("Enter the roll number: ");
        scanf("%d", &students[i].rollNumber);

        printf("Enter the physics marks: ");
        scanf("%d", &students[i].physicsMarks);

        printf("Enter the chemistry marks: ");
        scanf("%d", &students[i].chemistryMarks);

        printf("Enter the mathematics marks: ");
        scanf("%d", &students[i].mathematicsMarks);

        students[i].totalMarks = students[i].physicsMarks + students[i].chemistryMarks + students[i].mathematicsMarks;
    }

    struct Student temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].totalMarks < students[j + 1].totalMarks) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\nMerit List:\n");
    printf("--------------------------------------------------\n");
    printf("Roll Number \t Name \t Total PCM Marks \n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("\t %d \t %s \t %d \n", students[i].rollNumber, students[i].name, students[i].totalMarks);
    }

    printf("--------------------------------------------------\n");

    return 0;
}
