#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
} node;

node *create();
void insert(node *, node *);
void preorder(node *);
void inorder(node *);
void postorder(node *);

int main()
{
    int ch;
    node *root = NULL, *temp;
    printf("Enter number of nodes ");
    scanf("%d", &ch);
    printf("Enter the data for the nodes ");
    do
    {
        temp = create();
        if (root == NULL)
            root = temp;
        else
        {
            insert(root, temp);
        }
        ch--;
    } while (ch != 0);

    printf("Preorder Traversal");
    preorder(root);
    printf("Inorder traversal");
    inorder(root);
    printf("Postorder Traversal");
    postorder(root);
    printf("\n");
    return 0;
}

node *create()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    scanf("%d", &temp->data);
    temp->left = temp->right = NULL;
    return temp;
}

void insert(node *root, node *temp)
{
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        if (temp->data < root->data)
        {
            if (root->left == NULL)
                root->left = temp;
            else
            {
                insert(root->left, temp);
            }
        }
        if (temp->data > root->data)
        {
            if (root->right != NULL)
            {
                insert(root->right, temp);
            }
            else
            {
                root->right = temp;
            }
        }
    }
}

void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d \t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \t", root->data);
        inorder(root->right);
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d \t", root->data);
    }
}