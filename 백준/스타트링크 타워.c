#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZERO    "####.##.##.####"
#define ONE     "..#..#..#..#..#"
#define TWO     "###..#####..###"
#define THREE   "###..####..####"
#define FOUR    "#.##.####..#..#"
#define FIVE    "####..###..####"
#define SIX     "####..####.####"
#define SEVEN   "###..#..#..#..#"
#define EIGHT   "####.#####.####"
#define NINE    "####.####..####"

int *make_arr(char *str)
{
    char    *strs[10] = { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE };
    int     i;
    int     j;
    int     *arr;

    arr = (int *)malloc(sizeof(int) * 10);
    i = 0;
    while (i < 10)
    {
        arr[i] = 1;
        j = 0;
        while (j < 15)
        {
            if (str[j] == '#' && strs[i][j] == '.')
            {
                arr[i] = 0;
                break;
            }
            j++;
        }
        i++;
    }
    return (arr);
}

int **parsing_str(char **str, int n)
{
    int     **arr;
    int     i;
    int     j;
    int     k;
    char    tmp[16];

    arr = (int **)malloc(sizeof(int *) * n);
    i = 0;
    k = 0;
    while (i < n)
    {
        j = 0;
        while (j < 5)
        {
            strncpy(&tmp[j * 3], &str[j][k], 3);           
            j++;
        }
        k += 4;
        arr[i] = make_arr(tmp);
        i++;
    }
    return (arr);
}

long long make_number(int **arr, int n, int index, int num)
{   
    int         i;
    int         flag;
    long long   temp;
    long long   sum;

    if (index >= n)
        return (num);
    sum = 0;
    flag = 0;
    i = 0;
    while (i < 10)
    {
        if (arr[index][i] == 1)
        {
            flag = 1;
            temp = make_number(arr, n, index + 1, num * 10 + i);
            if (temp == -1)
                return (temp);
            sum += temp;
        }
        i++;
    }
    if (flag == 0)
        sum = -1;
    return (sum);
}

double solve(int **arr, int n)
{
    double  ret;
    int     i;
    int     j;
    double  tmp;

    tmp = 1;
    i = 0;
    while (i < n)
    {
        ret = 0;
        j = 0;
        while (j < 10)
        {
            if (arr[i][j] == 1)
                ret++;
            j++;
        }
        if (ret != 0)
            tmp *= ret;
        i++;
    }
    ret = make_number(arr, n, 0, 0);
    if (ret > 0)
        ret = ret / tmp;
    return (ret);
}

int main(void)
{
    int     N;
    int     i;
    char    **str;
    int     **arr;

    scanf("%d\n", &N);
    str = (char **)malloc(sizeof(char *) * 5);
    i = 0;
    while (i < 5)
    {
        str[i] = (char *)malloc(sizeof(char) * (4 * N + 1));
        scanf("%s\n", str[i]);
        i++;
    }
    arr = parsing_str(str, N);
    /*
    for (int j = 0; j < N; j++)
    {
        printf("arr[%d] : ", j);
        for (int k = 0; k < 10; k++)
            printf("%d, ", arr[j][k]);
        printf("\n");
    }
    */
    printf("%f", solve(arr, N));
    return (0);
}