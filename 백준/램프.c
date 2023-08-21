#include <stdio.h>
#include <stdlib.h>

int *make_off(int **arr, int n, int m)
{
    int *off;
    int i;
    int j;

    off = (int *)malloc(sizeof(int) * n);
    i = 0;
    while (i < n)
    {
        off[i] = 0;
        j = 0;
        while (j < m)
        {
            if (arr[i][j] == 0)
                off[i]++;
            j++;
        }
        i++;
    }
    return (off);
}

int *make_col(int **arr, int n, int m)
{
    int *col;
    int i;
    int j;
    int k;

    col = (int *)malloc(sizeof(int) * n);
    i = 0;
    while (i < n)
    {
        col[i] = 0;
        j = 0;
        while (j < n)
        {
            k = 0;
            while (k < m)
            {
                if (arr[i][k] != arr[j][k])
                    break;
                k++;
            }
            if (k == m)
                col[i]++;
            j++;
        }
        i++;
    }
    return (col);
}

int solve(int **arr, int n, int m, int k)
{
    int *off;
    int *col;
    int i;
    int ret = 0;

    off = make_off(arr, n, m);
    col = make_col(arr, n, m);
    ret = 0;
    i = 0;
    while (i < n)
    {
        if (off[i] <= k && (k - off[i]) % 2 == 0)
        {
            if (ret < col[i])
                ret = col[i];
        }
        i++;
    }
    return (ret);
}

int main(void)
{
    int     N;
    int     M;
    int     K;
    int     i;
    int     j;
    char    *str;
    int     **arr;

    scanf("%d %d\n", &N, &M);
    str = (char *)malloc(sizeof(char) * M + 1);
    arr = (int **)malloc(sizeof(int *) * N);
    i = 0;
    while (i < N)
    {
        scanf("%s\n", str);
        arr[i] = (int *)malloc(sizeof(int) * M);
        j = 0;
        while (j < M)
        {
            arr[i][j] = str[j] - '0';
            j++;
        }
        i++;
    }
    scanf("%d\n", &K);
    printf("%d\n", solve(arr, N, M, K));
    return (0);
}