#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode
{
    int data;
    struct QueueNode * next;
}Queue;

Queue * front, * rear;

void DisplayQueue()
{
    if ((front == NULL) && (rear == NULL))
    {
        printf("the queue is empty\n");
    }
    else
    {
        Queue * temp = front;
        while (temp != rear)
        {
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
        printf("%d \n", temp -> data);
    }
}

void enqueue ()
{
    int value;
    printf("enter the value to be enqueued: ");
    scanf("%d", &value);
    Queue * temp;
    temp = (Queue *)malloc(sizeof(Queue));
    temp -> data = value;
    temp -> next = NULL;
    if (front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear -> next = temp;
        rear = temp;
    }
    DisplayQueue();
}

void dequeue ()
{
    Queue * temp;
    if ((front == NULL) && (rear == NULL))
    {
        printf("UNDERFLOW\n");
    }
    else if (front == rear)
    {
        temp = front;
        front = rear = NULL;
        printf("the dequeued element is: %d\n", temp -> data);
        free(temp);
        DisplayQueue();
    }
    else
    {
        temp = front;
        front = front -> next;
        printf("the dequeued element is: %d\n", temp -> data);
        free(temp);
        DisplayQueue();
    }
}

int main()
{
    printf("choice:\n");
    printf("1. enqueue\n2. dequeue\n3. exit\n");
    int ch;
    while (1)
    {
        printf("enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: exit(0);
            default : printf("invalid choice\n");
        }
    }
}