#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct Node* next;
} node;

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

node* top = NULL;

void push() {
    node* n = createNode();
    n->next = top;
    top = n;
    printf("%d pushed to the stack\n", n->data);
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty, cannot pop\n");
        return;
    }
    node* temp = top;
    top = top->next;
    printf("%d popped from the stack\n", temp->data);
    free(temp);
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    node* temp = top;
    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void main () {
    int choice=0;
    while(choice != 4) {
        printf("\n\nMenu");
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
        printf("\nEnter your choice \n");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting....");
                break;
            default:
                printf("Please Enter valid choice ");

        };
    }
}
