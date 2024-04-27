#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

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

    n->next = head;
    head = n;

    printf("Node inserted");
}

void insertAtEnd(){
    node *n, *ptr;
    n = createNode();

    if(head == NULL){
        head = n;
    } else {
        ptr = head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = n;
    }

    printf("Node inserted");
}

void insertAtSpecificPos(){
    node *n, *ptr;
    n = createNode();

    int pos, c=1;
    printf("Enter position:");
    scanf("%d", &pos);

    ptr = head;
    while(ptr!=NULL && c < pos-1){
        c++;
        ptr = ptr->next;
    }

    if(ptr == NULL){
        printf("Position not accessible.");
        free(n);
        return;
    } else {
        if(pos == 1){
            n->next = head;
            head=n;
        } else {
            n->next = ptr->next;
            ptr->next = n;
        }
        printf("Node inserted");
    }
}

void deleteAtBeg(){
    node *ptr;

    if(head == NULL){
        printf("List is empty");
        return;
    } else {
        ptr = head;
        head = ptr->next;
        free(ptr);

        printf("Node deleted");
    }
}

void deleteAtEnd(){
    node *ptr, *follow;

    if(head == NULL){
        printf("List is empty");
        return;
    }

    ptr = head;
    follow = NULL;
    while(ptr->next != NULL){
        follow = ptr;
        ptr = ptr->next;
    }

    if(ptr == head){
        head = NULL;
    } else {
        follow->next = NULL;
    }
    free(ptr);
    printf("Node deleted");
}

void deleteAtSpecificPos(){
    node *ptr, *follow;

    if(head == NULL){
        printf("List is empty");
        return;
    }

    int pos, c=0;
    printf("Enter position:");
    scanf("%d", &pos);

    ptr = head;
    follow = NULL;

    while(ptr != NULL && c < pos-1){
        follow = ptr;
        ptr = ptr->next;
        c++;
    }

    if(ptr == NULL){
        printf("Position not accesssible");
        return;
    }

    if(pos == 1){
        head = ptr->next;
        free(ptr);
    } else {
        follow->next = ptr->next;
        free(ptr);
    }
    printf("Node deleted");
}

void display(){
    if(head == NULL){
        printf("List is empty");
        return;
    }

    node *ptr;

    ptr = head;
    while(ptr != NULL){
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
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
    int c = 0;
    node *ptr = head;
    while(ptr != NULL){
        c++;
        ptr = ptr->next;
    }
    return c;
}

int search(int key){
    node *ptr = head;
    int loc = 1;

    while(ptr != NULL){
        if(ptr->data == key){
            return loc;
        }
        ptr = ptr->next;
        loc++;
    }
    return -1;;
}

void sort(){
    node *ptr = head, *follow = NULL;
    int temp;

    if(head == NULL){
        return;
    }

    while(ptr != NULL){
        follow = ptr->next;
        while(follow != NULL){
            if(ptr->data > follow->data){
                temp = ptr->data;
                ptr->data = follow->data;
                follow->data = temp;
            }
            follow = follow->next;
        }
        ptr = ptr->next;
    }
}

void reverse(){
    node *ptr = head;
    node *prev = NULL, *next = NULL;

    if(head == NULL){
        return;
    }

    while(ptr != NULL){
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    head = prev;
}

void main(){
    int c, nodes, key;

    while(1){
        printf("\n\nMENU\n");
        printf("\n1. Create.\n2. Insert at beginning.\n3. Insert at end.\n4. Insert at specific position.\n5. Delete from beginning.\n6. Delete from end.\n7. Delete from specific position.\n8. Display.\n9. Count no. of nodes.\n10. Search.\n11. Sort.\n12. Reverse.\n13. Exit");
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
                insertAtSpecificPos();
                break;
            case 5:
                deleteAtBeg();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                deleteAtSpecificPos();
                break;
            case 8:
                printf("Linked List:\n");
                display();
                break;
            case 9:
                nodes = countNodes();
                printf("Total no. of nodes in linked list = %d", nodes);
                break;
            case 10:
                printf("Enter node you want to search: ");
                scanf("%d", &key);
                if(search(key) == -1){
                    printf("%d not found", key);
                } else {
                    printf("%d found at %d", key, search(key));
                }
                break;
            case 11:
                printf("Original Linked List:\n");
                display();
                printf("\nSorted Linked List:");
                sort();
                display();
                break;
            case 12:
                printf("Original Linked List:\n");
                display();
                printf("\nReversing the linked list:\n");
                reverse();
                display();
            break;
            case 13:
                exit(0);
                break;
            default:
                printf("Invalid choice");
        }
    }

}
