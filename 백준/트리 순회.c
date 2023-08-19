#include <stdio.h>
#include <stdlib.h>

typedef struct s_tree
{
    struct s_tree *left;
    struct s_tree *right;
    char data;
} t_tree;

t_tree *create_node(char data)
{
    t_tree *node;

    node = (t_tree *)malloc(sizeof(t_tree));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return (node);
}

void insert_tree_left(t_tree *head, t_tree *node)
{
    if (head != NULL)
    {
        if (head->left != NULL)
            insert_tree_left(head->left, node);
        else
            head->left = node;
    }
    else
        head = node;
}

void insert_tree_right(t_tree *head, t_tree *node)
{
    if (head != NULL)
    {
        if (head->right != NULL)
            insert_tree_right(head->right, node);
        else
            head->right = node;
    }
    else
        head = node;
}

t_tree *find_tree_node(t_tree *head, char data)
{
    t_tree  *p;
    
    p = NULL;
    if (head != NULL)
    {
        if (head->data == data)
            return (head);
        if (head->left != NULL)
        {
            p = find_tree_node(head->left, data);
            if (p != NULL)
                return (p);
        }
        if (head->right != NULL)
        {
            p = find_tree_node(head->right, data);
            if (p != NULL)
                return (p);
        }
    }
    return (p);
}

void preorder_print(t_tree *head)
{
    if (head != NULL)
    {
        printf("%c", head->data);
        preorder_print(head->left);
        preorder_print(head->right);
    }
}

void inorder_print(t_tree *head)
{
    if (head != NULL)
    {
        inorder_print(head->left);
        printf("%c", head->data);
        inorder_print(head->right);
    }
}

void postorder_print(t_tree *head)
{
    if (head != NULL)
    {
        postorder_print(head->left);
        postorder_print(head->right);
        printf("%c", head->data);
    }
}

int main(void)
{
    int n;
    int i;
    char info[3];
    t_tree *head;
    t_tree *find;

    scanf("%d\n", &n);
    i = 0;
    head = NULL;
    while (i < n)
    {
        scanf("%c %c %c\n", &info[0], &info[1], &info[2]);
        if (head == NULL)
        {
            head = create_node(info[0]);
            if (info[1] != '.')
                insert_tree_left(head, create_node(info[1]));
            if (info[2] != '.')
                insert_tree_right(head, create_node(info[2]));
        }
        else
        {
            find = find_tree_node(head, info[0]);
            if (info[1] != '.')
                insert_tree_left(find, create_node(info[1]));
            if (info[2] != '.')
                insert_tree_right(find, create_node(info[2]));
        }
        i++;
    }
    preorder_print(head);
    printf("\n");
    inorder_print(head);
    printf("\n");
    postorder_print(head);
    printf("\n");
    return (0);
}