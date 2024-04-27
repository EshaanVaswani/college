#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct Node* next;
} node;

typedef struct queue {
    struct node* front;
    struct node* rear;
} queue;

node *createNode(){
    node *n;
    n = (node *)malloc(sizeof(node *));

    if(n == NULL){
        printf("OVERFLOW");
        return NULL;
    }

    printf("\nEnter data:");
    scanf("%d", &n->data);

    n->next = NULL;
    return n;
}

queue* initializeQueue() {
    queue* q = (queue *)malloc(sizeof(queue *));
    if (q == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(queue* q) {
    node* n = createNode();
    if (q->rear == NULL) {
        q->front = n;
        q->rear = n;
    } else {
        q->rear->next = n;
        q->rear = n;
    }
    printf("%d enqueued into the queue\n", n->data);
}

void dequeue(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty, cannot dequeue\n");
        return;
    }
    node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    printf("%d dequeued from the queue\n", temp->data);
    free(temp);
}

void display(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main () {
    int choice=0;
    queue* q = initializeQueue();
    while(choice != 4) {
        printf("\n\nMenu");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter your choice \n");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                enqueue(q);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting....");
                break;
            default:
                printf("Please Enter valid choice ");

        };
    }
}
