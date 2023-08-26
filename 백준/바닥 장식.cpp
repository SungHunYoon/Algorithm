#include <iostream>
#include <vector>

using namespace std;

void row(vector<vector<char>> &table, int c, int r, int m)
{
    for (int i = c; i < m; i++)
    {
        if (table[r][i] == '-')
            table[r][i] = '.';
        else
            return ;
    }
}

void column(vector<vector<char>> &table, int r, int c, int n)
{
    for (int i = r; i < n; i++)
    {
        if (table[i][c] == '|')
            table[i][c] = '.';
        else
            return ;
    }
}

int count(vector<vector<char>> arr, int n, int m)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != '.')
            {
                if (arr[i][j] == '-')
                    row(arr, j, i, m);
                else
                    column(arr, i, j, n);
                cnt++;
            }
        }
    }
    return (cnt);
}

int main(void)
{
    int n;
    int m;
    vector<vector<char>> arr;

    cin >> n;
    cin >> m;
    arr.assign(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    cout << count(arr, n, m) << endl;
    return (0);
}