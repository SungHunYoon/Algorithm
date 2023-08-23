#include <stdio.h>
#include <stdlib.h>

int is_sort(int *arr, int n)
{
    int i;

    i = 0;
    while (i + 1 < n)
    {
        if (arr[i] > arr[i + 1])
            break;
        i++;
    }
    if (n == 0 || i + 1 == n)
        return (1);
    return (0);
}

typedef struct s_list
{
    struct s_list *next;
    int n;
    int *arr;
}   t_list;

t_list *create_node(int *arr, int n)
{
    t_list *node;
    int i;

    node = (t_list *)malloc(sizeof(t_list));
    node->next = NULL;
    node->n = n;
    node->arr = (int *)malloc(sizeof(int) * n);
    i = 0;
    while (i < n)
    {
        node->arr[i] = arr[i];
        i++;
    }
    return (node);
}

void    push_back(t_list **list, t_list *node)
{
    t_list *p;

    if (*list == NULL)
        *list = node;
    else
    {
        p = *list;
        while (p->next != NULL)
            p = p->next;
        p->next = node;
    }
}

void perm(t_list **list, int *arr, int *ref, int n, int index)
{
    int i;

    if (index == n)
    {
        push_back(list, create_node(arr, n));
        return ;
    }
    i = 0;
    while (i < n)
    {
        if (ref[i] == 0)
        {
            arr[index] = i;
            ref[i] = 1;
            perm(list, arr, ref, n, index + 1);
            ref[i] = 0;
        }
        i++;
    }
}

t_list *make_list(int n)
{
    t_list *list;
    int i;
    int *arr;
    int *ref;

    arr = (int *)malloc(sizeof(int) * n);
    ref = (int *)malloc(sizeof(int) * n);
    i = 0;
    while (i < n)
        ref[i++] = 0;
    perm(&list, arr, ref, n, 0);
    return (list);
}

void comb(t_list **list, int *arr, int s, int n, int index)
{
    int i;
    
    if (index == n)
    {
        push_back(list, create_node(arr, n));
        return ;
    }
    i = s;
    while (i < n)
    {
        arr[index] = i;
        comb(list, arr, i + 1, n, index + 1);
        i++;
    }
}

t_list *make_list_comb(int n)
{
    t_list *list;
    int i;
    int *arr;

    arr = (int *)malloc(sizeof(int) * n);
    comb(&list, arr, 0, n, 0);
    return (list);
}

int *solve(int *arr, int n)
{
    int i;
    int *b;
    t_list *p;

    b = (int *)malloc(sizeof(int) * n);
    //p = make_list(n);
    p = make_list_comb(n);
    while (p != NULL)
    {
        i = 0;
        while (i < n)
        {
            b[p->arr[i]] = arr[i];
            i++;
        }
        if (is_sort(b, n))
            return (p->arr);
        p = p->next;
    }
    return (NULL);
}

int *sol(int *arr, int n)
{
    int *b;
    int *p;
    int i;
    int j;
    int tmp;

    b = (int *)malloc(sizeof(int) * n);
    i = 0;
    while (i < n)
    {
        b[i] = i;
        i++;
    }
    i = n - 1;
    while (i > 0)
    {
        j = 0;
        while (j < i)
        {
            if(arr[j] > arr[j + 1])
            {
                tmp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = tmp;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;     
            }
            j++;
        }
        i--;
    }
    i = 0;
    printf("arr : ");
    while (i < n)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
    p = (int *)malloc(sizeof(int) * n);
    i = 0;
    while (i < n)
    {
        printf("%d ", b[i]);
        p[b[i]] = i;
        i++;
    }
    printf("\n");
    return (p);
}

int main(void)
{
    int n;
    int i;
    int *arr;
    int *answer;

    scanf("%d\n", &n);
    arr = (int *)malloc(sizeof(int) * n);
    i = 0;
    while (i < n)
    {
        scanf("%d\n", &arr[i]);
        i++;
    }
    //answer = solve(arr, n);
    answer = sol(arr, n);
    i = 0;
    while (i < n)
    {
        printf("%d", answer[i]);
        if (i + 1 < n)
            printf(" ");
        i++;
    }
    printf("\n");
    return (0);
}