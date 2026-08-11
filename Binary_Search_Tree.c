#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node* root, int value)
{
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct Node* findMin(struct Node* root)
{
    while(root->left != NULL)
        root = root->left;

    return root;
}

struct Node* deleteNode(struct Node* root, int value)
{
    if(root == NULL)
        return root;

    if(value < root->data)
        root->left = deleteNode(root->left, value);

    else if(value > root->data)
        root->right = deleteNode(root->right, value);

    else
    {
        if(root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        if(root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node* root = NULL;
    int n, value, deleteValue;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter element to insert: ");
        scanf("%d", &value);

        root = insert(root, value);
    }

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\n\nEnter element to delete: ");
    scanf("%d", &deleteValue);

    root = deleteNode(root, deleteValue);

    printf("After deletion: ");
    inorder(root);

    return 0;
}
/*
Output:

Enter number of elements to insert: 4
Enter element to insert: 2
Enter element to insert: 4
Enter element to insert: 5
Enter element to insert: 7

Inorder traversal: 2 4 5 7 

Enter element to delete: 4
After deletion: 2 5 7
*/