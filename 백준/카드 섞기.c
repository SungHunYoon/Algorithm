#include <stdio.h>
#include <stdlib.h>

int check(int *arr, int *p, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (arr[i] % 3 != p[i])
            return (0);
        i++;
    }
    return (1);
}

int solve(int *p, int *s, int n)
{
    int *arr;
    int *copy;
    int i;
    int cnt;

    arr = (int *)malloc(sizeof(int) * n);
    copy = (int *)malloc(sizeof(int) * n);
    i = 0;
    while (i < n)
    {
        arr[i] = i;
        i++;
    }
    cnt = 0;
    i = 0;
    while (check(arr, p, n) == 0)
    {
        i = 0;
        while (i < n)
        {
            copy[i] = arr[i];
            i++;
        }
        i = 0;
        while (i < n)
        {
            if (i == s[i] && arr[i] % 3 != p[i])
                return (-1);
            arr[i] = copy[s[i]];
            i++;
        }
        cnt++;
    }
    return (cnt);
}

int main(void)
{
    int N;
    int i;
    int *P;
    int *S;

    scanf("%d\n", &N);
    P = (int *)malloc(sizeof(int) * N);
    S = (int *)malloc(sizeof(int) * N);
    i = 0;
    while (i < N)
    {
        scanf("%d\n", &P[i]);
        i++;
    }
    i = 0;
    while (i < N)
    {
        scanf("%d\n", &S[i]);
        i++;
    }
    /*
    printf("P : ");
    for (int j = 0; j < N; j++)
        printf("%d, ", P[j]);
    printf("\n");
    printf("S : ");
    for (int j = 0; j < N; j++)
        printf("%d, ", S[j]);
    printf("\n");
    */
    printf("%d\n", solve(P, S, N));
    return (0);
}