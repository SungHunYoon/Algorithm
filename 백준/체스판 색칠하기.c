#include <stdio.h>
#include <stdlib.h>

int get_fill_cnt(char **board, int i, int j)
{
    int x;
    int y;
    int wb_cnt;
    int bw_cnt;
    char wb;
    char bw;

    y = i + 8;
    x = j + 8;
    wb_cnt = 0;
    bw_cnt = 0;
    while (i < y)
    {
        if (i % 2 == 0)
        {
            wb = 'W';
            bw = 'B';
        }
        else
        {
            wb = 'B';
            bw = 'W';
        }
        j = x - 8;
        while (j < x)
        {
            if (wb != board[i][j])
                wb_cnt++;
            if (bw != board[i][j])
                bw_cnt++;
            if (wb == 'W')
                wb = 'B';
            else
                wb = 'W';
            if (bw == 'B')
                bw = 'W';
            else
                bw = 'B';
            j++;
        }
        i++;
    }
    if (wb_cnt > bw_cnt)
        return (bw_cnt);
    else
        return (wb_cnt);
}

int main(void)
{
    int n;
    int m;
    int i;
    int j;
    char **board;
    int cnt;
    int tmp;

    scanf("%d %d\n", &n, &m);
    board = (char **)malloc(sizeof(char *) * n);
    i = 0;
    while (i < n)
    {
        board[i] = (char *)malloc(sizeof(char) * m);
        scanf("%s\n", board[i]);
        i++;
    }
    cnt = 10000000;
    i = 0;
    while (i <= n - 8)
    {
        j = 0;
        while (j <= m - 8)
        {
            tmp = get_fill_cnt(board, i, j);
            if (cnt > tmp)
                cnt = tmp;
            j++;
        }
        i++;
    }
    printf("%d\n", cnt);
    return (0);
}