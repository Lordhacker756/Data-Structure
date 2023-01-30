#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL, *q, *t;

void insertStart();
void insertEnd();
void insertPos();
void display();
void deleteBeg();
void deleteEnd();
void deletePos();

void main()
{
    int ch;

    while (1)
    {
        printf("SINGLE LINKED LIST\n");
        printf("Enter\n1 Insert at beginnig\n2 Insert at end \n3 Insert at Pos \n4 Delete from Beginning \n5 Delete from End \n6 Delete from Position \n7 Display \n8 Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertStart();
            break;

        case 2:
            insertEnd();
            break;

        case 3:
            insertPos();
            break;

        case 4:
            deleteBeg();
            break;

        case 5:
            deleteEnd();
            break;

        case 6:
            deletePos();
            break;

        case 7:
            display();
            break;

        case 8:
            exit(1);
            break;

        default:
            printf("Invalid Choice\n");
        }
    }
}

void insertStart()
{
    // When the list is empty
    // Create a new node and point the head node to it
    int num;
    t = (struct node *)malloc(sizeof(struct node));
    printf("Enter element ");
    scanf("%d", &num);
    t->data = num;
    if (start == NULL)
    {
        t->next = start;
        start = t;
    }
    // There is already some elements in the list
    else
    {
        t->next = start;
        start = t;
    }
}

void insertEnd()
{
    int num;
    t = (struct node *)malloc(sizeof(struct node));
    printf("Enter element");
    scanf("%d", &num);
    t->data = num;
    t->next = NULL;
    // In case the list is already empty
    if (start == NULL)
    {
        start = t;
    }
    // If the list has some elements
    else
    {
        q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = t;
    }
}

void insertPos()
{
    int num, pos, i = 0;
    t = (struct node *)malloc(sizeof(struct node));
    printf("Enter element ");
    scanf("%d", &num);
    printf("Enter position to insert at ");
    scanf("%d", &pos);
    q = start;
    for (i = 0; i < pos; i++)
    {
        if (q->next == NULL)
        {
            printf("The position is invalid! \n");
            return;
        }
        q = q->next;
    }
    t->next = q;
}

void deleteBeg()
{
    // if there is no element in the list
    if (start == NULL)
    {
        printf("There is no element to delete ");
        return;
    }

    else
    {
        q = start;
        start = start->next;
        printf("Element %d was deleted", q->data);
        free(q);
    }
}

void deleteEnd()
{
    // if there is no element in the list
    if (start == NULL)
    {
        printf("There is no element to delete ");
        return;
    }

    else
    {
        q = start;
        while (q->next->next != NULL)
        {
            q = q->next;
        }
        t->next = q->next->next;
        printf("The element %d was deleted", t->data);
        q->next = NULL;
        free(t);
    }
}

void deletePos()
{
    int pos, i;
    printf("Enter position to delete ");
    scanf("%d", &pos);

    q = start;
    for (i = 0; i < pos; i++)
    {
        if (q->next->next == NULL)
        {
            printf("The position is invalid \n");
            return;
        }
        q = q->next;
    }
    t->next = q->next;
    q->next = t->next;
    free(t);
}

void display()
{
    if (start == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        q = start;
        while (q != NULL)
        {
            printf("%2d - ", q->data);
            q = q->next;
        }
    }
}