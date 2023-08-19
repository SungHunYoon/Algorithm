#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    int i;
    int x;
    int y;
    int d;
    int sqr;

    scanf("%d\n", &n);
    i = 0;
    while (i < n)
    {
        scanf("%d %d\n", &x, &y);
        d = y - x;
        sqr = sqrt(d);
        if (d == sqr * sqr)
            printf("%d\n", 2 * sqr - 1);
        else if (d <= sqr * sqr + sqr)
            printf("%d\n", 2 * sqr);
        else
            printf("%d\n", 2 * sqr + 1);
        i++;
    }
    return (0);
}