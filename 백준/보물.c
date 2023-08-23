#include <stdio.h>
#include <stdlib.h>

int solve(int *a, int *b, int n)
{
    int i;
    int j;
    int ret;
    int min, min_i;
    int max, max_i;

    ret = 0;
    i = 0;
    while (i < n)
    {
        min = 101;
        max = -1;
        j = 0;
        while (j < n)
        {
            if (a[j] < min)
            {
                min = a[j];
                min_i = j;
            }
            if (b[j] > max)
            {
                max = b[j];
                max_i = j;
            }
            j++;
        }
        a[min_i] = 101;
        b[max_i] = -1;
        ret += max * min;
        i++;
    }
    return (ret);
}

int main(void)
{
    int n;
    int i;
    int *a;
    int *b;

    scanf("%d\n", &n);
    a = (int *)malloc(sizeof(int) * n);
    b = (int *)malloc(sizeof(int) * n);
    i = 0;
    while (i < n)
    {
        scanf("%d\n", &a[i]);
        i++;
    }
    i = 0;
    while (i < n)
    {
        scanf("%d\n", &b[i]);
        i++;
    }
    printf("%d\n", solve(a, b, n));
    return (0);
}