#include <stdio.h>
#include <stdlib.h>

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
        return (NULL);
    node->data = data;
    node->next = NULL;
    return (node);
}

void    enqueue(t_queue **queue, t_queue *node)
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

int    size(t_queue *queue)
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

int dfs(t_queue **queue, int i, int k)
{
    int     cnt;
    int     temp;
    t_queue *p;

    if (i == k)
        return (0);
    else if (queue[i] == NULL)
        return (1);
    cnt = 0;
    p = queue[i];
    while (p != NULL)
    {
        temp = dfs(queue, p->data, k);
        if (temp == 0 && size(queue[i]) == 1)
            cnt++;
        else
            cnt += temp;
        p = p->next;
    }
    return (cnt);
}

int main(void)
{
    int n;
    int m;
    int k;
    int i;
    int root;
    t_queue **queue;

    scanf("%d\n", &n);
    queue = (t_queue **)malloc(sizeof(t_queue *) * n);
    i = 0;
    while(i < n)
        queue[i++] = NULL;
    i = 0;
    while (i < n)
    {
        scanf("%d\n", &m);
        if (m == -1)
            root = i;
        else
            enqueue(&queue[m], create_node(i));
        i++;
    }
    scanf("%d\n", &k);
    printf("%d\n", dfs(queue, root, k));
    return (0);
}