#include <stdio.h>
#include <stdlib.h>
#define size 5

int queue[size], front = -1, rear = -1;

void enqueue()
{
    int value;

    if((front == rear + 1) || (front == 0 && rear == size - 1))
    {
        printf("Queue is Full");
    }
    else {
        printf("Enter any value:");
        scanf("%d", &value);

        if(front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % size;

        queue[rear] = value;

        printf("\nInserted Value is: %d", value);
    }
}

void dequeue()
{
    int value;

    if(front == -1)
    {
        printf("Queue is Empty");
    }
    else {
        value = queue[front];

        if(front == rear)
        {
            front = rear - 1;
        }
        else {
            front = (front + 1) % size;
        }

        printf("\nDeleted Value is: %d", value);
    }
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is Empty");
    }
    else {
        printf("\nFront is: %d", front);
        printf("\nvalue is:");
        for(i = front; i != rear; i = (i + 1) % size)
        {
            printf("%d ", queue[i]);
        }
        printf("%d ", queue[i]);
        printf("\nRear is: %d", rear);
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n\n1. Enqueue()\n");
        printf("2. Dequeue()\n");
        printf("3. Display()\n");
        printf("4. Exit\n");

        printf("\n\nEnter your choice:\n");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Choice:");
        }

    }

    return 0;
}
