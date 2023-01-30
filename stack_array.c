#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int top = -1, stack[MAX];

void push();
void pop();
void display();
void topElement();

int main()
{
    int ch;
    printf("STACK OPERATIONS\n");
    while (1)
    {
        printf("1. Push \n2. Pop \n3. Display \n4. Top Element\n5. Exit\n");
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
            topElement();
            break;
        case 5:
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
    if (top == MAX - 1)
    {
        printf("Stack Overflow!!");
        return;
    }
    else
    {
        printf("Enter element to push");
        scanf("%d", &elem);
        top++;
        stack[top] = elem;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is already empty! \n");
    }
    else
    {
        printf("Top element %d was deleted\n", stack[top]);
        top--;
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("The stack is empty! \n");
        return;
    }
    else
    {
        printf("The elements of stack are: ");
        for (i = top; i >= 0; i--)
        {
            printf(" %d ", stack[i]);
        }
    }
}

void topElement()
{
    if (top == -1)
    {
        printf("The stack is empty! \n");
        return;
    }
    else
    {
        printf("The top element is: ", stack[top]);
    }
}