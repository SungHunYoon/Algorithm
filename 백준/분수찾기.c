#include <stdio.h>

int main(void)
{
    int n;
    int i;
    int j;
    int line;

    scanf("%d\n", &n);
    i = 0;
    line = 1;
    while (i + line < n)
    {
        i += line;
        line++;
        //printf("i : %d, line : %d\n", i, line);
    }
    j = 0;
    while (j < line)
    {
        if (i + 1 + j == n)
        {
            if (line % 2 == 0)
                printf("%d/%d\n", j + 1, line - j);
            else
                printf("%d/%d\n", line - j, j + 1);
            break;
        }
        j++;
    }
    return (0);
}