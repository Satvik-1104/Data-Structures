#include <stdio.h>
#include <stdlib.h>

int Rear = -1;
int Front = -1;

void Enqueue(int Size, int Queue[Size], int Data)
{
    if (((Rear + 1)% Size) == Front)
    {
        printf("OVERFLOW\n");
        return;
    }
    else if (Front == -1 && Rear == -1)
    {
        Front = 0;
        Rear = 0;
        Queue[Rear] = Data;
    }
    else
    {
        Rear = (Rear + 1) % Size;
        Queue[Rear] = Data;
        if (Front == -1)
        {
            Front = 0;
        }
    }
}


void Dequeue(int Size, int Queue[Size])
{
    if (Front == -1 && Rear == -1)
    {
        printf("UNDERFLOW\n");
        return;
    }
    else if (Front == Rear)
    {
        int temp = Queue[Front];
        Front = -1;
        Rear = -1;
        printf("The dequeued element is %d\n", temp);
    }
    else
    {
        int temp = Queue[Front];
        Front = (Front + 1) % Size;
        printf("The dequeued element is %d\n", temp);
    }
}

void Display(int Size, int Queue[Size])
{
    if (Front == -1 && Rear == -1)
    {
        printf("UNDERFLOW\n");
        return;
    }
    else 
    {
        int t = Front;
        while (t != Rear)
        {
            printf("%d ", Queue[t]);
            t = (t + 1) % Size; 
        }
        printf("%d\n", Queue[t]);
    }
}

int main()
{
    printf("Enter the size of Circular Queue: ");
    int Size;
    scanf("%d", &Size);
    printf("Enter the number of elements you want to enter in the queue: ");
    int e;
    scanf("%d", &e);
    int Queue[Size];
    printf("Enter %d elements:\n", e);
    for (int i = 0; i < e; i++)
    {
        int Data;
        scanf("%d", &Data);
        Enqueue(Size, Queue, Data);
    }

    Display(Size, Queue);
    printf("The front is pointing to position %d\n", Front);
    printf("The rear is pointing to position %d\n", Rear);

    printf("enter the choice:\n");
    printf("1. enqueue\n2. dequeue\n3. exit\n");

    int ch;
    while(1)
    {
        printf("enter your choice: ");
        scanf("%d", &ch);
        int pos;

        switch (ch)
        {
            case 1:
                if (((Rear + 1)% Size) == Front)
                {
                    printf("OVERFLOW\n");
                }  
                else
                {
                    printf("Enter the position to enqueue at: ");
                    scanf("%d", &pos);
                    if (pos == (Rear+1))
                    {
                        int ee;
                        printf("Enter the element to be enqueued: ");
                        scanf("%d", &ee);
                        Enqueue(Size, Queue, ee);
                    }
                    else
                    {
                        printf("In a queue, an element can only be enqueued at the rear.\n");
                    }

                    Display(Size, Queue);
                    printf("The front is pointing to position %d\n", Front);
                    printf("The rear is pointing to position %d\n", Rear);
                }
                break;

            case 2:
                if (Front == -1 && Rear == -1)
                {
                    printf("UNDERFLOW\n");
                }

                else
                {
                    printf("Enter the position to dequeue at: ");
                    scanf("%d", &pos);
                    if (pos == Front)
                    {
                        Dequeue(Size, Queue);
                    }
                    else
                    {
                        printf("In a queue, an element can only be dequeued from the front.\n");
                    }

                    Display(Size, Queue);
                    printf("The front is pointing to position %d\n", Front);
                    printf("The rear is pointing to position %d\n", Rear);
                    }
                    break;

            case 3:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}