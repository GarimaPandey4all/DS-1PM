#include <stdio.h>
#include <stdlib.h>

struct  node {
    int info;
    struct node *link;
};

struct node *START = NULL;

struct node *createNode()
{
    struct node *n;

    n = (struct node *)malloc(sizeof(struct node));

    return (n);
};

void insertNode()
{
    struct node *temp, *t;

    temp = createNode();

    printf("Enter any number:");
    scanf("%d", &temp->info);

    temp->link = NULL;

    if(START == NULL)
    {
        START = temp;
    }
    else {

        t = START;

        while(t->link != NULL)
        {
            t = t->link;
        }

        t->link = temp;
    }
}

void deleteNode()
{
    struct node *t;

    if(START == NULL)
    {
        printf("List is Empty");
    }
    else {
        t = START;

        START = START->link;

        free(t);
    }
}

void viewList()
{
    struct node *t;

    if(START == NULL)
    {
        printf("List is Empty");
    }
    else {
        t = START;

        while(t != NULL)
        {
            printf("%d  ", t->info);
            t = t->link;
        }
    }
}


void searchList()
{
    struct node *t;
    int search;

    if(START != NULL)
    {
        t = START;

        printf("Enter any number to be search:");
        scanf("%d", &search);

        while(t != NULL)
        {
            if(t->info == search)
            {
                printf("%d search value is found.", search);
            }

            t = t->link;
        }
    }
    else {
        printf("List is Empty. Invalid Search");
    }
}


int main()
{
    int choice;

    while(1)
    {
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. ViewList");
    printf("\n4. SearchList");
    printf("\n5. Exit");
    printf("\n\nEnter your choice:");
    scanf("%d", &choice);

    switch(choice)
    {
    case 1:
        insertNode();
        break;

    case 2:
        deleteNode();
        break;

    case 3:
        viewList();
        break;

    case 4:
        searchList();
        break;

    case 5:
        exit(0);

    default:
        printf("Invalid Choice");

    }
}
    return 0;
}
