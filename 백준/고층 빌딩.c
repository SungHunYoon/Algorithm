#include <stdio.h>
#include <stdlib.h>

float slope(int x1, int x2, int y1, int y2)
{
    return (((float)y1 - (float)y2) / ((float)x1 - (float)x2));
}

int calculate(int *arr, int n)
{
    int     i;
    int     j;
    int     ret;
    int     lCnt;
    int     rCnt;
    float   left;
    float   right;
    float   temp;

    ret = 0;
    i = 0;
    while (i < n)
    {
        // Right
        j = i + 1;
        rCnt = 0;
        while (j < n)
        {
            if (j == i + 1)
            {
                right = slope(i, j, arr[i], arr[j]);
                rCnt++;
            }
            else
            {
                temp = slope(i, j, arr[i], arr[j]);
                if (temp > right)
                {
                    right = temp;
                    rCnt++;
                }
            }
            j++;
        }
        // Left
        j = i - 1;
        lCnt = 0;
        while (j >= 0)
        {
            if (j == i - 1)
            {
                left = slope(i, j, arr[i], arr[j]);
                lCnt++;
            }
            else
            {
                temp = slope(i, j, arr[i], arr[j]);
                if (temp < left)
                {
                    left = temp;
                    lCnt++;
                }
            }
            j--;
        }
        if (ret < lCnt + rCnt)
            ret = lCnt + rCnt;
        i++;
    }
    return (ret);
}

int main(void)
{
    int     N;
    int     i;
    int     *arr;

    scanf("%d\n", &N);
    arr = (int *)malloc(sizeof(int) * (N));
    if (arr == NULL)
        return (0);
    i = 0;
    while (i < N)
    {
        scanf("%d\n", &arr[i]);
        i++;
    }
    printf("%d\n", calculate(arr, N));
    return (0);
}