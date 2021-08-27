#include <stdio.h>
#include <stdlib.h>

struct node {

    struct node *prev;
    int info;
    struct node *next;
};

struct node *START = NULL;

struct node *searchNode()
{
    struct node *temp;
    int search;

    if(START == NULL)
    {
        return NULL;
    }

    else {
        printf("Enter any value to be search:");
        scanf("%d", &search);

        temp = START;

        while(temp != NULL)
        {
            if(temp->info == search)
            {
                return temp;
            }
            temp = temp->next;
        }

        return NULL;
    }
};

struct node *createNode()
{
    struct node *n;

    n = (struct node *)malloc(sizeof(struct node));

    return(n);
};

//insert at start position only once
void insertAtStart()
{
    struct node *temp;

    if(START == NULL)
    {
        temp = createNode();

        temp->prev = NULL;

        printf("Enter any number:");
        scanf("%d", &temp->info);

        temp->next = NULL; //START;

        START = temp;
    }
    else {
        printf("List has some nodes");
    }
}

void insertAtLast()
{
    struct node *temp, *temp1;

    temp = createNode();

    printf("Enter any number:");
    scanf("%d", &temp->info);

    temp->next = NULL;

    if(START == NULL)
    {
        temp->prev = NULL;
        START = temp;
    }
    else {
        temp1 = START;

        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }

        temp->prev = temp1;
        temp1->next = temp;
    }
}

void insertAfterNode()
{
    struct node *temp, *ptr;

    ptr = searchNode();

    if(ptr == NULL)
    {
        printf("Invalid search. List is Empty");
    }
    else {

        temp = createNode();

        printf("Enter any number:");
        scanf("%d", &temp->info);

        temp->prev = ptr;
        temp->next = ptr->next;

        if(ptr->next != NULL)
        {
            ptr->next->prev = temp;
        }

        ptr->next = temp;
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
            t = t->next;
        }
    }
}

void deleteFirstNode()
{
    struct node *temp;

    if(START == NULL)
    {
        printf("List is Empty");
    }
    else {
        temp = START;

        START = START->next;
        START->prev = NULL;

        free(temp);
    }
}

void deleteLastNode()
{
    struct node *temp;

    if(START == NULL)
    {
        printf("List is Empty");
    }
    else {
        temp = START;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        if(START->next == NULL)
        {
            START = NULL;
        }
        else {
            temp->prev->next = NULL;
        }

        free(temp);
    }
}

void deleteIntermediateNode()
{
    struct node *ptr;

    ptr = searchNode();

    if(ptr == NULL)
    {
        printf("Invalid Search. List is Empty");
    }
    else if(ptr->prev == NULL || ptr->next == NULL) {
        printf("Invalid Deletion");
    }
    else {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;

        free(ptr);
    }
}

int main()
{
    int choice;

    while(1)
    {
    printf("\n1. Insert Start");
    printf("\n2. Insert Last");
    printf("\n3. Insert After Node");
    printf("\n4. Delete Start");
    printf("\n5. Delete Last");
    printf("\n6. Delete Intermediate Node");
    printf("\n7. ViewList");
    printf("\n8. Exit");
    printf("\n\nEnter your choice:");
    scanf("%d", &choice);

    switch(choice)
    {
    case 1:
        insertAtStart();
        break;

    case 2:
        insertAtLast();
        break;

    case 3:
        insertAfterNode();
        break;

    case 4:
        deleteFirstNode();
        break;

    case 5:
        deleteLastNode();
        break;

    case 6:
        deleteIntermediateNode();
        break;

    case 7:
        viewList();
        break;

    case 8:
        exit(0);

    default:
        printf("Invalid Choice");

    }
}

    return 0;
}
