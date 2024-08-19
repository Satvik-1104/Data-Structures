#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform inorder traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to check if the tree is complete
bool isCompleteTree(struct Node* root, int index, int nodeCount) {
    if (root == NULL)
        return true;

    // If the index of the current node is greater than or equal to the number of nodes, it is not a complete tree
    if (index >= nodeCount)
        return false;

    // Recursively check the left and right subtrees
    return (isCompleteTree(root->left, 2 * index + 1, nodeCount) && isCompleteTree(root->right, 2 * index + 2, nodeCount));
}

// Function to free the memory allocated to the tree
void freeTree(struct Node* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int data, choice;
    struct Node* root = NULL;

    // User input for constructing the binary tree
    do {
        printf("Enter the data for a node (or -1 to stop): ");
        scanf("%d", &data);
        if (data == -1)
            break;

        if (root == NULL)
            root = createNode(data);
        else {
            struct Node* temp = root;
            while (true) {
                printf("Enter the left(0) or right(1) child of %d: ", temp->data);
                scanf("%d", &choice);
                if (choice == 0) {
                    if (temp->left == NULL) {
                        temp->left = createNode(data);
                        break;
                    }
                    temp = temp->left;
                } else if (choice == 1) {
                    if (temp->right == NULL) {
                        temp->right = createNode(data);
                        break;
                    }
                    temp = temp->right;
                } else {
                    printf("Invalid choice! Please enter 0 or 1.\n");
                }
            }
        }
    } while (true);

    // Inorder traversal of the tree
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Checking if the tree is complete or not
    int nodeCount = 0;
    struct Node* countTemp = root;
    while (countTemp != NULL) {
        nodeCount++;
        countTemp = countTemp->left;
    }
    bool isComplete = isCompleteTree(root, 0, nodeCount);

    if (isComplete)
        printf("The tree is complete.\n");
    else
        printf("The tree is not complete.\n");

    // Freeing the allocated memory
    freeTree(root);

    return 0;
}