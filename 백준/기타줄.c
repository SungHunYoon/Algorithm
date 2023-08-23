#include <stdio.h>
#include <stdlib.h>

int min_arr(int **arr, int index, int m)
{
    int i;
    int min;

    min = 1000;
    i = 0;
    while (i < m)
    {
        if (min > arr[i][index])
            min = arr[i][index];
        i++;
    }
    return (min);
}

int solve(int **arr, int n, int m)
{
    int i;
    int omin;
    int smin;
    int cnt;

    smin = min_arr(arr, 0, m);
    omin = min_arr(arr, 1, m);
    cnt = 0;
    if (smin < omin * 6)
    {
        cnt += smin * (n / 6);
        n %= 6;
    }
    if (n < 6 && smin < omin * n)
        cnt += smin;
    else
        cnt += omin * n;
    return (cnt);
}

int main(void)
{
    int n;
    int m;
    int i;
    int **arr;

    scanf("%d %d\n", &n, &m);
    arr = (int **)malloc(sizeof(int *) * m);
    i = 0;
    while (i < m)
    {
        arr[i] = (int *)malloc(sizeof(int) * 2);
        scanf("%d %d\n", &arr[i][0], &arr[i][1]);
        i++;
    }
    printf("%d\n", solve(arr, n, m));
    return (0);
}