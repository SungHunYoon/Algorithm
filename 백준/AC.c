#include <stdio.h>
#include <stdlib.h>

void    process(char *p, int *arr, int n)
{
    int reverse;
    int front;
    int rear;

    reverse = 0;
    front = 0;
    rear = n - 1;
    while (*p != '\0')
    {
        if (*p == 'R')
            reverse = !reverse;
        else
        {
            if (front > rear)
            {
                printf("error\n");
                return ;
            }
            if (reverse == 0)
                front++;
            else
                rear--;
        }
        p++;
    }
    printf("[");
    if (reverse == 0)
    {
        while (front <= rear)
        {
            printf("%d", arr[front]);
            if (front++ < rear)
                printf(",");
        }
    }
    else
    {
        while (rear >= front)
        {
            printf("%d", arr[rear]);
            if (rear-- > front)
                printf(",");
        }
    }
    printf("]\n");
}

int *make_arr(char *x, int n)
{
    int *arr;
    int i;

    if (n == 0)
        return (NULL);
    arr = (int *)malloc(sizeof(int) * n);
    if (arr == NULL)
        return (NULL);
    i = 0;
    while (i < n)
    {
        while (*x < '0' || *x > '9')
            x++;
        arr[i] = atoi(x);
        while (*x >= '0' && *x <= '9')
            x++;
        i++;
    }
    return (arr);
}

int main(void)
{
    int     T;
    char    p[100001];
    int     n;
    char    x[400002];
    int     i;
    int     *arr;

    scanf("%d\n", &T);
    i = 0;
    while (i < T)
    {
        scanf("%s\n", &p);
        scanf("%d\n", &n);
        scanf("%s\n", &x);
        arr = make_arr(x, n);
        process(p, arr, n);
        i++;
    }
    return (0);
}