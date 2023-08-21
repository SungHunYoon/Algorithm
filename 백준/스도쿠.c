#include <stdio.h>

int check(int (*arr)[9], int x, int y)
{
    int i;
    int j;

    // X Axis
    i = 0;
    while (i < 9)
    {
        if (i != x && arr[y][i] == arr[y][x])
            return (0);
        i++;
    }
    // Y Axis
    i = 0;
    while (i < 9)
    {
        if (i != y && arr[i][x] == arr[y][x])
            return (0);
        i++;
    }
    // Box
    i = y / 3 * 3;
    while (i < (y / 3 + 1) * 3)
    {
        j = x / 3 * 3;
        while (j < (x / 3 + 1) * 3)
        {
            if (i != y && j != x && arr[i][j] == arr[y][x])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int recursive(int (*arr)[9], int x, int y)
{
    int i;

    if (x >= 9)
    {
        x = 0;
        y++;
        if (y >= 9)
            return (1);
    }
    if (arr[y][x] != 0)
    {
        if (recursive(arr, x + 1, y) == 1)
            return (1);
    }
    else
    {
        i = 0;
        while (i < 9)
        {
            arr[y][x] = i + 1;
            if (check(arr, x, y) == 1)
            {
                if (recursive(arr, x + 1, y) == 1)
                    return (1);
            }
            arr[y][x] = 0;
            i++;
        }
    }
    return (0);
}

int main(void)
{
    int     i;
    int     j;
    char    str[10];
    int     arr[9][9];

    i = 0;
    while (i < 9)
    {
        scanf("%s\n", str);
        j = 0;
        while (j < 9)
        {
            arr[i][j] = str[j] - '0';
            j++;
        }
        i++;
    }
    if (recursive(arr, 0, 0) == 1)
    {
        i = 0;
        while (i < 9)
        {
            j = 0;
            while (j < 9)
            {
                printf("%d", arr[i][j]);
                j++;
            }
            printf("\n");
            i++;
        }
    }
    return (0);
}