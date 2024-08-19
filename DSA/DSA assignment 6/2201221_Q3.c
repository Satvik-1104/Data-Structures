#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1;
}

struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = postorder[(*postIndex)--];
    node->left = NULL;
    node->right = NULL;

    if (inStart == inEnd) {
        return node;
    }

    int inIndex = search(inorder, inStart, inEnd, node->data);
    if (inIndex == -1) {
        printf("Error: Invalid inorder and postorder traversals!");
        exit(1);
    }

    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void printTree(struct Node* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 5;

    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    printTree(root->left, space);
}

int main() {
    printf("Enter the inorder traversal:\n");
    int inorder[100];
    int i = 0;
    int value;

    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        inorder[i++] = value;
    }

    printf("Enter the postorder traversal:\n");
    int postorder[100];
    i = 0;

    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        postorder[i++] = value;
    }

    int n = i;

    int postIndex = n - 1;
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Inorder traversal of the constructed binary tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder traversal of the constructed binary tree: ");
    postorderTraversal(root);
    printf("\n");

    printf("Tree structure:\n");
    printTree(root, 0);

    return 0;
}
