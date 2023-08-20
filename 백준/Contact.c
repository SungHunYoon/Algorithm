#include <stdio.h>
#include <string.h>

int pattern1(char *n)
{
    int i;

    i = 0;
    if (strncmp(&n[i], "10", 2) == 0)
    {
        i += 2;
        if (n[i] == '0')
        {
            while (n[i] == '0')
                i++;
            if (n[i] == '1')
                i++;
            else
                return (0);
        }
        else
            return (0);
    }
    return (i);
}

int process(char *n)
{
    int i;
    int temp;
    int flag;

    flag = 0;
    i = 0;
    while (n[i] != '\0')
    {
        temp = pattern1(&n[i]);
        if (temp > 0)
        {
            flag = 1;
            i += temp;
        }
        else if (strncmp(&n[i], "01", 2) == 0)
        {
            i += 2;
            flag = 0;
        }
        else
        {
            if (flag == 1 && n[i] == '1')
                i++;
            else
                return (0);
        }
    }
    return (1);
}

int main(void)
{
    int     T;
    char    n[201];
    int     i;

    scanf("%d\n", &T);
    i = 0;
    while (i < T)
    {
        scanf("%s\n", n);
        if (process(n) == 1)
            printf("YES\n");
        else
            printf("NO\n");
        i++;
    }
    return (0);
}