#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int i, top = -1, stack[MAX];

//insert into a stack
void push()
{
    int value;

    if(top == MAX - 1)
    {
        printf("Stack Overflow");
    }
    else {
        printf("Enter any value:");
        scanf("%d", &value);

        top++;
        stack[top] = value;
    }
}

//delete from a stack
void pop()
{
    int value;

    if(top == -1)
    {
        printf("Stack Underflow");
    }
    else {
        value = stack[top];

        printf("The deleted value is: %d", value);

        top--;
    }
}

void display()
{
    if(top == -1)
    {
        printf("Stack Underflow");
    }
    else {
        printf("The values of the stack are:\n");
        for(i = top; i >= 0; i--)
        {
            printf("%d  ", stack[i]);
        }
    }
}


int main()
{
    int choice;

    while(1)
    {
        printf("\n\n1. Push()\n");
        printf("2. Pop()\n");
        printf("3. Display()\n");
        printf("4. Exit\n");

        printf("\n\nEnter your choice:\n");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
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
