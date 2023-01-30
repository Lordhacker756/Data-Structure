#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct stack
{
    int arr[MAX];
    int top;
};

void init_stack();
void push();
void pop();
void display();
void topElement();

int main()
{
    int ch;
    printf("STACK OPERATIONS\n");
    struct stack ptr;
    init_stack(&ptr);
    while (1)
    {
        printf("1. Push \n2. Pop \n3. Display \n4. Top Element\n5. Exit\n");
        printf("Enter your choice ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push(&ptr);
            break;
        case 2:
            pop(&ptr);
            break;

        case 3:
            display(&ptr);
            break;

        case 4:
            topElement(&ptr);
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

void init_stack(struct stack *st)
{
    st->top = -1;
}

void push(struct stack *st)
{
    int elem;
    if (st->top == MAX - 1)
    {
        printf("Stack Overflow!!");
        return;
    }
    else
    {
        printf("Enter element to push");
        scanf("%d", &elem);
        st->top++;
        st->arr[st->top] = elem;
    }
}

void pop(struct stack *st)
{

    if (st->top == -1)
    {
        printf("Stack is already empty! \n");
    }
    else
    {
        printf("Top element %d was deleted\n", st->arr[st->top]);
        st->top--;
    }
}

void display(struct stack *st)
{
    int i;
    if (st->top == -1)
    {
        printf("The stack is empty! \n");
        return;
    }
    else
    {
        printf("The elements of stack are: ");
        for (i = st->top; i >= 0; i--)
        {
            printf(" %d ", st->arr[i]);
        }
    }
}

void topElement(struct stack *st)
{
    if (st->top == -1)
    {
        printf("The stack is empty! \n");
        return;
    }
    else
    {
        printf("The top element is: ", st->arr[st->top]);
    }
}