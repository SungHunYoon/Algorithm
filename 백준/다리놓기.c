#include <stdio.h>

int calculate(int a, int b)
{
    int i;
    int answer;

    i = 0;
    answer = 1;
    while (i < a)
    {
        answer *= b - i;
        printf("answer1 : %d\n", answer);
        answer /= 1 + i;
        printf("answer2 : %d\n", answer);
        i++;
    }
    return (answer);
}

int main(void)
{
    int n;
    int i;
    int b[2];

    scanf("%d\n", &n);
    i = 0;
    while (i < n)
    {
        scanf("%d %d\n", &b[0], &b[1]);
        printf("%d\n", calculate(b[0], b[1]));
        i++;
    }
    return (0);
}