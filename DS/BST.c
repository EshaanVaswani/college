#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    struct node* left;
    int data;
    struct node* right;
} node;

node *root = NULL;

node* createNode(int data){
    node* n;

    n = (node*)malloc(sizeof(node));
    if(n != NULL){
        n->data = data;
        n->left = NULL;
        n->right = NULL;

        return n;
    }
}

node* insert(node* root, int data){
    node* n;
    n = createNode(data);

    if(n!=NULL){
        if(root == NULL){
            root = n;
        } else {
            if(data > root->data){
                root->right = insert(root->right, data);
            } else {
                root->left = insert(root->left, data);
            }
        }
    }
    return root;
}

void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

node* findMin(node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

node* findMax(node* root){
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

node* search(node* root, int key){
    if(root == NULL || root->data == key){
        return root;
    } else {
        if(key < root->data){
            return search(root->left, key);
        } else {
            return search(root->right, key);
        }
    }
}

node* delete(node* root, int key){
    if(root == NULL){
        return root;
    } else {
        if(key < root->data){
            root->left = delete(root->left, key);
        } else if(key > root->data){
            root->right = delete(root->right, key);
        } else {
                if(root->left == NULL){
                    node* temp = root->right;
                    free(root);
                    return temp;
                } else if(root->right == NULL){
                    node* temp = root->left;
                    free(root);
                    return temp;
                }
                node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = delete(root->right, temp->data);
        }
        return root;
    }
}

void display(node* root){
    int c;
    printf("\nEnter order of traversal:\n1. Preorder\n2. Postorder\n3. Inorder\n");
    scanf("%d", &c);

    switch(c){
        case 1:
            preorder(root);
            break;
        case 2:
            postorder(root);
            break;
        case 3:
            inorder(root);
            break;
    }
}

int countNodes(node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countInternalNodes(node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return 0;
    }
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

int countLeafNodes(node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int height(node* root){
    if(root == NULL){
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void main(){
    int ch, data, nodes, intNodes, leafNodes, h;

    while(1){
        printf("\nBST Operations:\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Count no. of nodes\n6. Count no. of leaf nodes\n7. Count no. of Internal Nodes\n8. Height of tree\n9. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter data you want to insert:");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Node inserted\n");
                break;
            case 2:
                printf("Enter element you want to search:");
                scanf("%d", &data);
                if(search(root, data) == NULL){
                    printf("Element not found.\n");
                } else {
                    printf("Element found.\n");
                }
                break;
            case 3:
                printf("Enter element you want to delete:");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 4:
                display(root);
                break;
            case 5:
                nodes = countNodes(root);
                printf("Total no. of nodes = %d", nodes);
                break;
            case 6:
                leafNodes = countLeafNodes(root);
                printf("Total no. of leaf nodes = %d", leafNodes);
                break;
            case 7:
                intNodes = countInternalNodes(root);
                printf("Total no. of internal nodes = %d", intNodes);
                break;
            case 8:
                h = height(root);
                printf("Height of tree = %d", h);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
