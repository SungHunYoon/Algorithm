#include <stdio.h>
#include <stdlib.h>

int solve(int *arr, int l, int n)
{
    int i;
    int j;
    int min;
    int max;
    int cnt;

    min = 0;
    max = 1000;
    i = 0;
    while (i < l)
    {
        if (arr[i] == n)
            return (0);
        else if (arr[i] < n && min < arr[i])
            min = arr[i];
        else if (arr[i] > n && max > arr[i])
            max = arr[i];
        i++;
    }
    cnt = 0;
    i = min + 1;
    while (i < max)
    {
        j = i + 1;
        while (j < max)
        {
            if (i <= n && n <= j)
                cnt++;
            j++;
        }
        i++;
    }
    return (cnt);
}

int main(void)
{
    int l;
    int n;
    int i;
    int *arr;

    scanf("%d\n", &l);
    arr = (int *)malloc(sizeof(int) * l);
    i = 0;
    while (i < l)
    {
        scanf("%d\n", &arr[i]);
        i++;
    }
    scanf("%d\n", &n);
    printf("%d\n", solve(arr, l, n));
    return (0);
}