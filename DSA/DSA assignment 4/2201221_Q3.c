#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
    char data;
    struct StackNode* next;
}stacknode;

stacknode* createNode(char data)
{
    stacknode* newNode = (stacknode*)malloc(sizeof(stacknode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(stacknode* top)
{
    return top == NULL;
}

void push(stacknode** top, char data)
{
    stacknode* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

char pop(stacknode** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    stacknode* temp = *top;
    char popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

// Function to check if the input string contains balanced parenthesis
int isBalanced(char* str) {
    stacknode* stack = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(&stack, str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (isEmpty(stack)) {
                return 0;
            }
            char top = pop(&stack);
            if ((str[i] == ')' && top != '(') || (str[i] == '}' && top != '{') || (str[i] == ']' && top != '[')) {
                return 0;
            }
        }
    }
    // If it returns 0, it implies that the parenthesis are not balanced
    return isEmpty(stack);  // Balanced if stack is empty after processing the entire string
}

int main() {
    char str[100];
    printf("Enter a string containing parentheses: ");
    gets(str);
    printf("String: %s\n", str);
    if (isBalanced(str)) {
        printf("Balanced\n");
    } else {
        printf("Not balanced\n");
    }
    return 0;
}