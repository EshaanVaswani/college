#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 4

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

bool isFull() {
    if(rear == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

bool isEmpty() {
    if(front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        queue[rear] = item;
        printf("%d enqueued successfully.\n", item);
    }
}

int dequeue() {
    int item = -1;
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        item = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
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
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int frontVal() {
    if (isEmpty()) {
        printf("Queue is empty. No front value.\n");
        return -1;
    }
    return queue[front];
}

int rearVal() {
    if (isEmpty()) {
        printf("Queue is empty. No rear value.\n");
        return -1;
    }
    return queue[rear];
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
