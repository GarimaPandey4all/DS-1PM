#include <stdio.h>
#include <stdlib.h>

struct node {

    int info;
    struct node *link;
};

struct node *last = NULL;

struct node *createNode()
{
    struct node *n;

    n = (struct node *)malloc(sizeof(struct node));

    return (n);
};

//insert at empty list
void insertAtEmpty()
{
    struct node *temp;

    if(last == NULL)
    {
        temp = createNode();

        printf("Enter any number:");
        scanf("%d", &temp->info);

        last = temp;
        last->link = last;
    }

    else {

        printf("List is not Empty");
    }
}

void insertAtStart()
{
    struct node *temp;

    if(last == NULL)
    {
        printf("List is Empty");
    }
    else {
        temp = createNode();

        printf("Enter any number:");
        scanf("%d", &temp->info);

        temp->link = last->link;
        last->link = temp;
    }
}

void insertAtEnd()
{
    struct node *temp;

    if(last == NULL)
    {
        printf("List is Empty");
    }
    else {
        temp = createNode();

        printf("Enter any number:");
        scanf("%d", &temp->info);

        temp->link = last->link;
        last->link = temp;

        last = temp;
    }
}

void insertAfterNode()
{
    struct node *temp, *ptr;
    int search;

    if(last == NULL)
    {
        printf("List is Empty");
        return;
    }

    printf("Enter any value to be search:");
    scanf("%d", &search);

    ptr = last->link;

    do {
        if(ptr->info == search)
        {
            temp = createNode();

            printf("Enter any number:");
            scanf("%d", &temp->info);

            temp->link = ptr->link;
            ptr->link = temp;

            if(ptr == last)
            {
                last = temp;
            }
            return;
        }
        ptr = ptr->link;

    }while(ptr != last->link);

    printf("Search is not found in a list");
    return;
}

void deleteNode()
{
    struct node *t, *p;
    int search;

    if(last == NULL)
    {
        printf("List is Empty");
        return;
    }

    printf("Enter any value to be search:");
    scanf("%d", &search);

    //If only one node exist in a list
    if(last == last->link && last->info == search)
    {
        t = last;
        last = NULL;
        free(t);
        return;
    }

    //If only two nodes exist in a list
    if(last->link->info == search)
    {
        t = last->link;
        last->link = t->link;
        free(t);
        return;
    }

    //If we have more than two nodes in a list

    p = last->link;

    while(p->link != last)
    {
        if(p->link->info == search)
        {
            t = p->link;
            p->link = t->link;
            free(t);
            return;
        }

        p = p->link;
    }

    // if we have more than two nodes in a list but we want to delete last node of a list
    if(last->info == search)
    {
        t = last;
        p->link = last->link;
        last = p;
        free(t);
        return;
    }

    printf("Search is not found");
    return;

}

void viewList()
{
    struct node *t;

    if(last == NULL)
    {
        printf("List is Empty");
    }
    else {
        t = last->link;

        do {
            printf("%d  ", t->info);
            t = t->link;
        }while(t != last->link);
    }
}


int main()
{

    int choice;

    while(1)
    {
    printf("\n1. Insert Empty");
    printf("\n2. Insert Start");
    printf("\n3. Insert End");
    printf("\n4. Insert After Node");
    printf("\n5. Delete Node");
    printf("\n6. ViewList");
    printf("\n7. Exit");
    printf("\n\nEnter your choice:");
    scanf("%d", &choice);

    switch(choice)
    {
    case 1:
        insertAtEmpty();
        break;

    case 2:
        insertAtStart();
        break;

    case 3:
        insertAtEnd();
        break;

    case 4:
        insertAfterNode();
        break;

    case 5:
        deleteNode();
        break;

    case 6:
        viewList();
        break;

    case 7:
        exit(0);

    default:
        printf("Invalid Choice");

    }
}


    return 0;
}
