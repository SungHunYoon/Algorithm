#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct s_tree
{
    struct s_tree *left;
    struct s_tree *right;
    int data;
} t_tree;

t_tree *create_node(int data)
{
    t_tree *node = (t_tree *)malloc(sizeof(t_tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void tree_insert(t_tree **tree, t_tree *node)
{
    if (*tree == NULL)
        *tree = node;
    else
    {
        if ((*tree)->data > node->data)
            tree_insert(&(*tree)->left, node);
        else
        {
            tree_insert(&(*tree)->right, node);
        }
    }
}

void postorder(t_tree *tree)
{
    if (tree != NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        cout << tree->data << '\n';
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    t_tree *tree = NULL;
    int num;
    while (cin >> num)
        tree_insert(&tree, create_node(num));
    postorder(tree);
    return (0);
}