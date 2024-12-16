/*
Name : Tanmay Sanjay Gaidhani
Roll No: 114
Class: SY-A
Batch : I
*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
};

struct TreeNode* createTreeNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->leftChild = newNode->rightChild = NULL;
    return newNode;
}

struct TreeNode* addNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createTreeNode(value);
    }
    if (value < root->value) {
        root->leftChild = addNode(root->leftChild, value);
    } else {
        root->rightChild = addNode(root->rightChild, value);
    }
    return root;
}

struct TreeNode* findMinNode(struct TreeNode* root) {
    while (root->leftChild != NULL) {
        root = root->leftChild;
    }
    return root;
}

struct TreeNode* removeNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        printf("Node not found\n");
        return root;
    }
    if (value < root->value) {
        root->leftChild = removeNode(root->leftChild, value);
    } else if (value > root->value) {
        root->rightChild = removeNode(root->rightChild, value);
    } else {
        if (root->leftChild == NULL) {
            struct TreeNode* temp = root->rightChild;
            free(root);
            return temp;
        } else if (root->rightChild == NULL) {
            struct TreeNode* temp = root->leftChild;
            free(root);
            return temp;
        }
        struct TreeNode* temp = findMinNode(root->rightChild);
        root->value = temp->value;
        root->rightChild = removeNode(root->rightChild, temp->value);
    }

    return root;
}

void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preOrderTraversal(root->leftChild);
        preOrderTraversal(root->rightChild);
    }
}

void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->leftChild);
        printf("%d ", root->value);
        inOrderTraversal(root->rightChild);
    }
}

void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->leftChild);
        postOrderTraversal(root->rightChild);
        printf("%d ", root->value);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int option, number;
    do {
        printf("\nChoose an option:\n");
        printf("1. Add Node\n");
        printf("2. Remove Node\n");
        printf("3. Preorder Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &number);
                root = addNode(root, number);
                break;
            case 2:
                printf("Enter value to remove: ");
                scanf("%d", &number);
                root = removeNode(root, number);
                break;
            case 3:
                printf("Preorder Traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Inorder Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Program exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    } while (option != 6);
}
/*
OUTPUT
Choose an option:
1. Add Node
2. Remove Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 1
Enter value to add: 6

Choose an option:
1. Add Node
2. Remove Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 1
Enter value to add: 7

Choose an option:
1. Add Node
2. Remove Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 1
Enter value to add: 5

Choose an option:
1. Add Node
2. Remove Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 1
Enter value to add: 9

Choose an option:
1. Add Node
2. Remove Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 1
Enter value to add: 4

Choose an option:
1. Add Node
2. Remove Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 1
Enter value to add: 3

Choose an option:
1. Add Node
2. Remove Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 1
Enter value to add: 33

Choose an option:
1. Add Node
2. Remove Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 1
Enter value to add: 5

Choose an option:
1. Add Node
2. Remove Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 1
Enter value to add: 33

Choose an option:
1. Add Node
2. Remove Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 3
Preorder Traversal: 6 5 4 3 5 7 9 33 33 

Choose an option:
1. Add Node
2. Remove Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 4
Inorder Traversal: 3 4 5 5 6 7 9 33 33 

Choose an option:
1. Add Node
2. Remove Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 5
Postorder Traversal: 3 4 5 5 33 33 9 7 6 

Choose an option:
1. Add Node
2. Remove Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 2
Enter value to remove: 44
Node not found

Choose an option:
1. Add Node
2. Remove Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 33
Invalid choice, please try again

Choose an option:
1. Add Node
2. Remove Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 2
Enter value to remove: 33

Choose an option:
1. Add Node
2. Remove Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice:
*/