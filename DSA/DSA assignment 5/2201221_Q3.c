#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode
{
    int data;
    struct QueueNode* next;
} QueueNode;

QueueNode* front1, * rear1;
QueueNode* front2, * rear2;

void DisplayQueue(QueueNode* front, QueueNode* rear)
{
    if (front == NULL && rear == NULL)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        QueueNode* temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void Enqueue(QueueNode** front, QueueNode** rear)
{
    int value;
    printf("Enter the value to be enqueued: ");
    scanf("%d", &value);
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = value;
    temp->next = NULL;
    if (*front == NULL)
    {
        *front = *rear = temp;
    }
    else
    {
        (*rear)->next = temp;
        *rear = temp;
    }
    //DisplayQueue(*front, *rear);
}

void Dequeue(QueueNode** front, QueueNode** rear)
{
    if (*front == NULL && *rear == NULL)
    {
        printf("UNDERFLOW\n");
    }
    else if (*front == *rear)
    {
        QueueNode* temp = *front;
        *front = *rear = NULL;
        printf("The dequeued element is: %d\n", temp->data);
        free(temp);
        //DisplayQueue(*front, *rear);
    }
    else
    {
        QueueNode* temp = *front;
        *front = (*front)->next;
        printf("The dequeued element is: %d\n", temp->data);
        free(temp);
        //DisplayQueue(*front, *rear);
    }
}

int AreQueuesEqual(QueueNode* front1, QueueNode* rear1, QueueNode* front2, QueueNode* rear2) {
    QueueNode* current1 = front1;
    QueueNode* current2 = front2;

    while (current1 != NULL && current2 != NULL)
    {
        if (current1->data != current2->data)
            return 0;  // Queues are not equal
        current1 = current1->next;
        current2 = current2->next;
    }

    if (current1 == NULL && current2 == NULL)
        return 1;  // Queues are equal

    return 0;  // Queues are not equal
}

int main()
{
    front1 = rear1 = NULL;
    front2 = rear2 = NULL;

    printf("Choice:\n");
    printf("1. Enqueue to Queue 1\n2. Dequeue from Queue 1\n");
    printf("3. Enqueue to Queue 2\n4. Dequeue from Queue 2\n");
    printf("5. Check if queues are equal\n6. Exit\n");

    int ch;
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                Enqueue(&front1, &rear1);
                break;
            case 2:
                Dequeue(&front1, &rear1);
                break;
            case 3:
                Enqueue(&front2, &rear2);
                break;
            case 4:
                Dequeue(&front2, &rear2);
                break;
            case 5:
                printf("Queue 1: ");
                DisplayQueue(front1, rear1);
                printf("Queue 2: ");
                DisplayQueue(front2, rear2);
                if (AreQueuesEqual(front1, rear1, front2, rear2))
                    printf("Queues are equal.\n");
                else
                    printf("Queues are not equal.\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}