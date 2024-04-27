#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *last = NULL;

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

void insertAtBeg(){
    node *n;
    n = createNode();

    if(last == NULL){
        n->next = n;
        last = n;
    }

    n->next = last->next;
    last->next = n;

    printf("Node inserted");
}

void insertAtEnd(){
    node *n;
    n = createNode();

    if (last == NULL) {
        last = n;
        last->next = last;
    } else {
        n->next = last->next;
        last->next = n;
        last = n;
    }

    printf("Node inserted");
}

void insertAtPosition(int position) {
    node* n = createNode();

    if (last == NULL) {
        if (position != 1) {
            printf("Invalid position for an empty list\n");
            free(n);
            return;
        }
        last = n;
        last->next = last;
        return;
    }

    node* ptr = last->next;
    for (int i = 1; i < position - 1; ++i) {
        ptr = ptr->next;
        if (ptr == last->next) {
            printf("Invalid position\n");
            free(n);
            return;
        }
    }

    n->next = ptr->next;
    ptr->next = n;

    if (ptr == last && position == 1) {
        last = n;
    }

    printf("%d inserted at position %d\n", n->data, position);
}


void deleteAtBeg(){
    node* ptr;

    if(last == NULL){
        printf("List is empty");
        return;
    }

    ptr = last->next;

    if(ptr == last){
        free(ptr);
        last = NULL;
    } else {
        last->next = ptr->next;
        free(ptr);
    }

    printf("Node deleted");
}

void deleteAtEnd(){
    node *ptr = last;

    if(last == NULL){
        printf("List is empty");
        return;
    }

    if(last->next == last){
        free(last);
    } else {
        while(ptr->next->next != last){
            ptr = ptr->next;
        }
        free(ptr->next);
        ptr->next = last;
    }

    printf("Node deleted");
}

void deleteAtPosition(int position) {
    if (last == NULL) {
        printf("List is empty, cannot delete\n");
        return;
    }

    node* ptr = last->next;
    node* prev = NULL;

    for (int i = 1; i < position; ++i) {
        prev = ptr;
        ptr = ptr->next;
        if (ptr == last->next) {
            printf("Invalid position\n");
            return;
        }
    }

    if (prev == NULL) {
        last->next = ptr->next;
        free(ptr);
        if (ptr == last) {
            last = NULL;
        }
    } else {
        prev->next = ptr->next;
        free(ptr);
        if (ptr == last) {
            last = prev;
        }
    }

    printf("Node at position %d deleted\n", position);
}


void display(){
    if(last == NULL){
        printf("List is empty");
        return;
    }

    node *ptr;

    ptr = last->next;
    do {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    } while(ptr != last->next);
}

void create(){
    int n;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        insertAtEnd();
    }
}

int countNodes(){
    if(last == NULL){
        return 0;
    }
    int c = 1;

    node *ptr = last->next;
    do {
        c++;
        ptr = ptr->next;
    } while(ptr != last);

    return c;
}

int search(int key) {
    node *ptr;
    int position = 1;

    if (last == NULL) {
        printf("List is empty\n");
        return -1;
    }

    ptr = last->next;
    do {
        if (ptr->data == key) {
            return position;
        }
        ptr = ptr->next;
        position++;
    } while (ptr != last->next);
    return -1;
}



void sort() {
    node *ptr, *follow;
    int temp;

    if (last == NULL || last->next == last) {
        return;
    }

    ptr = last->next;

    do {
        follow = ptr->next;
        do {
            if (ptr->data < follow->data) {
                temp = ptr->data;
                ptr->data = follow->data;
                follow->data = temp;
            }
            follow = follow->next;
        } while (follow != last->next);
        ptr = ptr->next;
    } while (ptr != last->next);
}

void main(){
    int c, nodes, key, p;

    while(1){
        printf("\n\nMENU\n");
        printf("\n1. Create.\n2. Insert at beginning.\n3. Insert at end.\n4. Delete from beginning.\n5. Delete from end.\n6. Display.\n7. Count no. of nodes.\n8. Sort.\n9. Search\n10. Insert At Position.\n11. Delete From Position.\n12. Exit");
        printf("\nEnter choice:");
        scanf("%d",&c);

        switch(c){
            case 1:
                create();
                break;
            case 2:
                insertAtBeg();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                deleteAtBeg();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Linked List:\n");
                display();
                break;
            case 7:
                nodes = countNodes();
                printf("Total no. of nodes in linked list = %d", nodes);
                break;
            case 8:
                printf("Original Linked List:\n");
                display();
                printf("\nSorted Linked List:\n");
                sort();
                display();
                break;
            case 9:
                printf("Enter node you want to search: ");
                scanf("%d", &key);
                if(search(key) == -1){
                    printf("%d not found", key);
                } else {
                    printf("%d found at %d", key, search(key));
                }
                break;
            case 10:
                printf("Enter position you want to insert:");
                scanf("%d", &p);
                insertAtPosition(p);
                break;
            case 11:
                printf("Enter position you want to delete:");
                scanf("%d", &p);
                deleteAtPosition(p);
                break;
            case 12:
                exit(0);
                break;
            default:
                printf("Invalid choice");
        }
    }

}
