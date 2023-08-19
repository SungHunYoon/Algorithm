#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_queue
{
    struct s_queue  *next;
    int             data;
}   t_queue;

t_queue *create_node(int data)
{
    t_queue *node;

    node = (t_queue *)malloc(sizeof(t_queue));
    if (node == NULL)
        return node;
    node->next = NULL;
    node->data = data;
    return (node);
}

void    push(t_queue **queue, t_queue *node)
{
    t_queue *p;

    if (*queue == NULL)
        *queue = node;
    else
    {
        p = *queue;
        while (p->next != NULL)
            p = p->next;
        p->next = node;
    }
}

t_queue *pop(t_queue **queue)
{
    t_queue *p;

    if (*queue == NULL)
        return (NULL);
    p = *queue;
    if (p->next != NULL)
        *queue = p->next;
    else
        *queue = NULL;
    return (p);
}

int size(t_queue *queue)
{
    int cnt;

    cnt = 0;
    while (queue != NULL)
    {
        cnt++;
        queue = queue->next;
    }
    return (cnt);
}

int empty(t_queue *queue)
{
    if (queue == NULL)
        return (1);
    else
        return (0);
}

t_queue *front(t_queue *queue)
{
    return (queue);
}

t_queue *back(t_queue *queue)
{
    if (queue != NULL)
    {
        while (queue->next != NULL)
            queue = queue->next;
    }
    return (queue);
}

int main(void)
{
    int n;
    int i;
    char str[20];
    t_queue *queue;
    t_queue *temp;

    scanf("%d\n", &n);
    i = 0;
    queue = NULL;
    while (i < n)
    {
        scanf("%s\n", str);
        if (strncmp(str, "push", 4) == 0)
        {
            scanf("%s\n", str);
            push(&queue, create_node(atoi(str)));
        }
        else if (strncmp(str, "pop", 3) == 0)
        {
            temp = pop(&queue);
            if (temp == NULL)
                printf("-1\n");
            else
                printf("%d\n", temp->data);
        }
        else if (strncmp(str, "size", 4) == 0)
        {
            printf("%d\n", size(queue));
        }
        else if (strncmp(str, "empty", 5) == 0)
        {
            printf("%d\n", empty(queue));
        }
        else if (strncmp(str, "front", 5) == 0)
        {
            temp = front(queue);
            if (temp == NULL)
                printf("-1\n");
            else
                printf("%d\n", temp->data);
        }
        else if (strncmp(str, "back", 4) == 0)
        {
            temp = back(queue);
            if (temp == NULL)
                printf("-1\n");
            else
                printf("%d\n", temp->data);
        }
        i++;
    }
    return (0);
}