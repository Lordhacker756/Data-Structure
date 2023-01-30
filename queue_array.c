#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int front = -1, rear = -1, queue[MAX];

void push();
void pop();
void display();
void topElement();

int main()
{
    int ch;
    printf("QUEUE OPERATIONS\n");
    while (1)
    {
        printf("1. Insert \n2. Delete \n3. Display \n4. Exit\n");
        printf("Enter your choice ");
        scanf("%d", &ch);
        switch (ch)
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
            exit(1);

        default:
            printf("Invalid Choice! \n");
            break;
        }
    }
    return 0;
}

void push()
{
    int elem;
    if (rear == MAX - 1)
    {
        printf("Queue Overflow!!");
        return;
    }
    else
    {
        printf("Enter element to push");
        scanf("%d", &elem);
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = elem;
    }
}

void pop()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is already empty! \n");
    }
    else
    {
        printf("Element %d was deleted\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if (front == -1 || front > rear)
    {
        printf("The Queue is empty! \n");
        return;
    }
    else
    {
        printf("The elements of stack are: ");
        for (i = front; i <= rear; i++)
        {
            printf(" %d ", queue[i]);
        }
    }
}
