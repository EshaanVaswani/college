#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5 // Maximum size of the circular queue

int cQueue[MAX_SIZE];
int front = -1;
int rear = -1;

bool isFull() {
    if((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1)))
        return 1;
    else
        return 0;
}

bool isEmpty() {
    if(front == -1)
        return 1;
    else
        return 0;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        cQueue[rear] = item;
        printf("%d enqueued successfully.\n", item);
    }
}

int dequeue() {
    int item = -1; // Default value for an empty queue
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        item = cQueue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        printf("%d dequeued successfully.\n", item);
    }
    return item;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (true) {
            printf("%d ", cQueue[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }
        printf("\n");
    }
}

int frontVal() {
    if (isEmpty()) {
        printf("Queue is empty. No front value.\n");
        return -1;
    }
    return cQueue[front];
}

int rearVal() {
    if (isEmpty()) {
        printf("Queue is empty. No rear value.\n");
        return -1;
    }
    return cQueue[rear];
}

int main() {
    int choice, item;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Front\n");
        printf("5. Rear\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                if (item != -1) {
                    printf("Dequeued element: %d\n", item);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                item = frontVal();
                if (item != -1) {
                    printf("Front value: %d\n", item);
                }
                break;
            case 5:
                item = rearVal();
                if (item != -1) {
                    printf("Rear value: %d\n", item);
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice < 6);

    return 0;
}
