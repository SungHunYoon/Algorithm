#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[9][9];
int visit[9][9];

int check_sudoku(int x, int y, int n)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[y][i] == n)
            return (0);
    }

    for (int i = 0; i < 9; i++)
    {
        if (arr[i][x] == n)
            return (0);
    }

    int max_i = (y / 3 + 1) * 3;
    int max_j = (x / 3 + 1) * 3;

    for (int i = y / 3 * 3; i < max_i; i++)
    {
        for (int j = x / 3 * 3; j < max_j; j++)
        {
            if (arr[i][j] == n)
                return (0);
        }
    }
    return (1);
}

int recursive(int x, int y)
{
    if (x == 9)
    {
        x = 0;
        y++;
    }
    if (y == 9)
        return (1);
    int ret = 0;
    if (arr[y][x] != 0)
        ret = recursive(x + 1, y);
    else
    {
        for (int i = 0; i < 9; i++)
        {
            if (!visit[y][x])
            {
                if (check_sudoku(x, y, i + 1) == 1)
                {
                    visit[y][x] = true;
                    arr[y][x] = i + 1;
                    ret = recursive(x + 1 ,y);
                    if (ret == 1)
                        return (ret);
                    arr[y][x] = 0;
                    visit[y][x] = false;
                }
            }
        }
    }
    return (ret);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> arr[i][j];
    
    recursive(0, 0);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }

    return (0);
}