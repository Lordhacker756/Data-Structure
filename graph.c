#include <stdio.h>
int queue[20], stack[20], vis[20], a[20][20], top = -1, rear = -1, front = -1;
int delete();
void add(int item);
void push(int item);
int pop();
void bfs(int s, int n);
void dfs(int s, int n);

void main()
{
    int n, i, j, s, ch;
    char c, dummy;
    printf("Enter number of vertices:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("ENTER 1 IF %d HAS A NODE WITH %d ELSE 0 \n");
            scanf("%d", &a[i][j]);
        }
    }
    printf("THE ADJACENT MATRIX: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    do
    {
        for (i = 0; i <= n; i++)
        {
            vis[i] = 0;
        }
        printf("CHOOSE YOUR OPTION\n 1] B.F.S\n 2] D.F.S\n 3] Quit\n");
        scanf("%d", &ch);
        printf("Enter your source vertex:\n");
        scanf("%d", &s);
        switch (ch)
        {
        case 1:
            bfs(s, n);
            break;
        case 2:
            dfs(s, n);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("INVALID CHOICE..!\n");
            break;
        }
        printf("DO YOU WANT TO CONTINUE ( Y / N ) ?\n");
        scanf("%c", &c);
        scanf("%c", &dummy);
    } while ((c == 'y') && (c == 'Y'));
}

void add(int item)
{
    if (rear == 19)
    {
        printf("QUEUE IS FULL\n");
    }
    else
    {
        if (rear == -1)
        {
            queue[++rear] = item;
            front++;
        }
        else
        {
            queue[++front] = item;
        }
    }
}

int delete()
{
    int k;
    if ((front == rear) && (front == -1))
    {
        return 0;
    }
    else
    {
        k = queue[++front];
        return k;
    }
}

void push(int item)
{
    if (rear == 19)
    {
        printf("STACK IS FULL\n");
    }
    else
    {
        stack[++top] = item;
    }
}

int pop()
{
    int k;
    if (top == -1)
    {
        return 0;
    }
    else
    {
        k = stack[top--];
        return k;
    }
}

void bfs(int s, int n)
{
    int p, i;
    add(s);
    vis[s] = 1;
    p = delete ();
    if (p != 0)
    {
        printf("%d", p);
    }
    while (p != 0)
    {
        for (i = 0; i <= n; i++)
        {
            if ((a[p][i] != 0) && (vis[i] != 0))
            {
                add(i);
                vis[i] = 1;
            }
        }
    }
    p = delete ();
    for (i = 0; i <= n; i++)
    {
        if (vis[i] == 0)
            bfs(i, n);
    }
}

void dfs(int s, int n)
{
    int p, i;
    push(s);
    vis[s] = 1;
    p = pop();
    if (p != 0)
    {
        printf("%d", p);
    }
    while (p != 0)
    {
        for (i = 1; i <= n; i++)
        {
            if ((a[p][i] != 0) && (vis[i] == 0))
            {
                push(i);
                vis[i] = 1;
            }
        }
        p = pop();
        if (p != 0)
        {
            printf("%d", p);
        }
    }
    for (i = 0; i <= n; i++)
    {
        if (vis[i] == 0)
            dfs(i, n);
    }
}