#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_stack
{
    struct s_stack  *next;
    int             data;
}   t_stack;

t_stack *create_node(int data)
{
    t_stack *node;

    node = (t_stack *)malloc(sizeof(t_stack));
    if (node == NULL)
        return node;
    node->next = NULL;
    node->data = data;
    return (node);
}

void    push(t_stack **stack, t_stack *node)
{
    if (*stack != NULL)
        node->next = *stack;
    *stack = node;
}

t_stack *pop(t_stack **stack)
{
    t_stack *p;

    if (*stack == NULL)
        return (NULL);
    p = *stack;
    if ((*stack)->next != NULL)
        *stack = (*stack)->next;
    else
        *stack = NULL;
    return (p);
}

int size(t_stack *stack)
{
    int cnt;

    cnt = 0;
    while (stack != NULL)
    {
        cnt++;
        stack = stack->next;
    }
    return (cnt);
}

int empty(t_stack *stack)
{
    if (stack == NULL)
        return (1);
    else
        return (0);
}

t_stack *top(t_stack *stack)
{
    return (stack);
}

int main(void)
{
    int n;
    int i;
    char str[20];
    t_stack *stack;
    t_stack *temp;

    scanf("%d\n", &n);
    i = 0;
    stack = NULL;
    while (i < n)
    {
        scanf("%s\n", str);
        if (strncmp(str, "push", 4) == 0)
        {
            scanf("%s\n", str);
            push(&stack, create_node(atoi(str)));
        }
        else if (strncmp(str, "pop", 3) == 0)
        {
            temp = pop(&stack);
            if (temp == NULL)
                printf("-1\n");
            else
                printf("%d\n", temp->data);
        }
        else if (strncmp(str, "size", 4) == 0)
        {
            printf("%d\n", size(stack));
        }
        else if (strncmp(str, "empty", 5) == 0)
        {
            printf("%d\n", empty(stack));
        }
        else if (strncmp(str, "top", 3) == 0)
        {
            temp = top(stack);
            if (temp == NULL)
                printf("-1\n");
            else
                printf("%d\n", temp->data);
        }
        i++;
    }
    return (0);
}