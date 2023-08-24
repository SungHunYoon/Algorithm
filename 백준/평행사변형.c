#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double solve(int *a, int *b, int *c)
{
    int d[6][2];

    d[0][0] = -a[0] + b[0] + c[0];
    d[0][1] = -a[1] + b[1] + c[1];
    
    d[1][0] = a[0] - b[0] + c[0];
    d[1][1] = a[1] - b[1] + c[1];

    d[2][0] = a[0] + b[0] - c[0];
    d[2][1] = a[1] + b[1] - c[1];

    int i;
    int flag;
    double temp;
    double min;
    double max;
    
    flag = 0;
    max = 0;
    min = 50000;
    i = 0;
    while (i < 3)
    {
        if (((a[0] - b[0] == d[i][0] - c[0] && a[1] - b[1] == d[i][1] - c[1]) && (a[0] - d[i][0] == b[0] - c[0] && a[1] - d[i][1] == b[1] - c[1])) &&
            (a[0] - c[0]) * (b[1] - d[i][1]) != (b[0] - d[i][0]) * (a[1] - c[1]))
        {
            temp = 2 * (sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2)) + sqrt(pow(b[0] - c[0], 2) + pow(b[1] - c[1], 2)));
            if (temp > max)
                max = temp;
            if (temp < min)
                min = temp;
            flag = 1;
            printf("1. Collect : D[%d] : (%d, %d)\n", i, d[i][0], d[i][1]);
        }
        else if (((a[0] - c[0] == b[0] - d[i][0] && a[1] - c[1] == b[1] - d[i][1]) && (a[0] - b[0] == c[0] - d[i][0] && a[1] - b[1] == c[1] - d[i][1])) &&
                (a[0] - d[i][0]) * (b[1] - c[1]) != (b[0] - c[0]) * (a[1] - d[i][1]))
        {
            temp = 2 * (sqrt(pow(a[0] - c[0], 2) + pow(a[1] - c[1], 2)) + sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2)));
            if (temp > max)
                max = temp;
            if (temp < min)
                min = temp;
            flag = 1;
            printf("2. Collect : D[%d] : (%d, %d)\n", i, d[i][0], d[i][1]);
        }
        else if (((a[0] - c[0] == d[i][0] - b[0] && a[1] - c[1] == d[i][1] - b[1]) && (a[0] - d[i][0] == c[0] - b[0] && a[1] - d[i][1] == c[1] - b[1])) &&
                (a[0] - b[0]) * (d[i][1] - c[1]) != (d[i][0] - c[0]) * (a[1] -b[1]))
        {
            temp = 2 * (sqrt(pow(a[0] - c[0], 2) + pow(a[1] - c[1], 2)) + sqrt(pow(c[0] - b[0], 2) + pow(c[1] - b[1], 2)));
            if (temp > max)
                max = temp;
            if (temp < min)
                min = temp;
            flag = 1;
            printf("3. Collect : D[%d] : (%d, %d)\n", i, d[i][0], d[i][1]);
        }
        printf("D[%d] : (%d, %d)\n", i, d[i][0], d[i][1]);
        i++;
    }
    if (flag == 0)
        return (-1);
    else
    {
        printf("min : %f, max : %f\n", min, max);
        return (max - min);
    }
}

int main(void)
{
    int a[2];
    int b[2];
    int c[2];

    scanf("%d %d\n", &a[0], &a[1]);
    scanf("%d %d\n", &b[0], &b[1]);
    scanf("%d %d\n", &c[0], &c[1]);
    printf("%.15f\n", solve(a, b, c));
    return (0);
}