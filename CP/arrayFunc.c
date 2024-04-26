#include <stdio.h>

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}

int searchArray(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int deleteElement(int arr[], int size, int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        return size - 1;
    }
    return size;
}

int insertElement(int arr[], int size, int index, int element) {
    if (size >= 0 && index <= size) {
        for (int i = size - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        return size + 1;
    }
    return size;
}

int main() {
    printf("ESHAAN VASWANI D-34 \n\n");

    int arr[100], size, choice, element, index, key;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display Array\n");
        printf("2. Sort Array\n");
        printf("3. Search Element\n");
        printf("4. Delete Element\n");
        printf("5. Insert Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
            case 2:
                sortArray(arr, size);
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                index = searchArray(arr, size, key);
                if (index == -1) {
                    printf("Element not found in the array.\n");
                } else {
                    printf("Element found at index %d.\n", index);
                }
                break;
            case 4:
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                size = deleteElement(arr, size, index);
                printf("Element deleted successfully.\n");
                break;
            case 5:
                printf("Enter the index to insert at: ");
                scanf("%d", &index);
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                size = insertElement(arr, size, index, element);
                printf("Element inserted successfully.\n");
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
