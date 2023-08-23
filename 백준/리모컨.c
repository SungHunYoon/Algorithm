#include <stdio.h>
#include <stdlib.h>

int *make_crash(int *arr, int m)
{
    int *crash;
    int i;

    crash = (int *)malloc(sizeof(int) * 10);
    i = 0;
    while (i < 10)
        crash[i++] = 0;
    i = 0;
    while (i < m)
        crash[arr[i++]] = 1;
    return (crash);
}

int get_digit(int n)
{
    int digit;

    digit = 0;
    if (n == 0)
        return (1);
    while (n > 0)
    {
        digit++;
        n /= 10;
    }
    return (digit);
}

int ch_calculate(int *crash, int n, int number, int digit)
{
    int ret;
    int t1;
    int t2;
    int i;

    if (get_digit(n) + 1 < digit)
        return abs(n - number) + get_digit(number);
    ret = 0;
    i = 0;
    while (i < 10)
    {
        if (crash[i] == 0)
        {
            if (number != 0)
            {
                t1 = abs(n - number) + get_digit(number);
                if (ret == 0 || t1 < ret)
                    ret = t1;
            }
            t2 = ch_calculate(crash, n, number * 10 + i, digit + 1);
            if (ret == 0 || t2 < ret)
                ret = t2;
        }
        i++;
    }
    return (ret);
}

int main(void)
{
    int n;
    int m;
    int i;
    int *arr;

    scanf("%d\n", &n);
    scanf("%d\n", &m);
    arr = (int *)malloc(sizeof(int) * m);
    i = 0;
    while (i < m)
    {
        scanf("%d\n", &arr[i]);
        i++;
    }
    int min;
    int ch = 100;
    int *crash = make_crash(arr, m);

    min = ch > n ? ch - n : n - ch;
    if (m == 10)
        printf("%d\n", min);
    else if (m == 0)
        printf("%d\n", get_digit(n) > min ? min : get_digit(n));
    else
    {
        ch = ch_calculate(crash, n, 0, 0);
        printf("move : %d, ch : %d\n", min, ch);
        printf("%d\n", ch > min ? min : ch);
    }
    return (0);
}