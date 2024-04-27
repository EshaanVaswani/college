#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hash(int key) {
    return key % SIZE;
}

void insert(int hashTable[], int key, int *c) {
    if((*c)!=SIZE){
		int index = hash(key);
		int in = hash(key);
		int i=1;

        while (hashTable[index] != -1) {
            index = (in + i * i) % SIZE;
            i++;
        }

        hashTable[index] = key;
        (*c)++;
	} else {
		printf("Hash table is full");
	}
}

int search(int hashTable[], int key) {
    int index = hash(key);
    int i=1;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + i * i) % SIZE;
        i++;
    }

    return -1;
}

void display(int hashTable[]) {
    printf("Hash Table: ");
    for (int i = 0; i < SIZE; ++i) {
        if (hashTable[i] != -1) {
            printf("\n %d   %d ", i, hashTable[i]);
        } else {
            printf("\n %d   -", i);
        }
    }
    printf("\n");
}

int main() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        hashTable[i] = -1;
    }

    int choice, key, c=0;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(hashTable, key, &c);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                if (search(hashTable, key) != -1) {
                    printf("Element %d found in the hash table\n", key);
                } else {
                    printf("Element %d not found in the hash table\n", key);
                }
                break;
            case 3:
                display(hashTable);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
