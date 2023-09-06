#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int check(vector<vector<int>> arr, int n, int x, int y)
{
    int color = -1;
    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (color == -1)
                color = arr[i][j];
            else
            {
                if (color != arr[i][j])
                    return (-1);
            }
        }
    }
    return (color);
}

pair<int, int> recursive(vector<vector<int>> &arr, int n, int x, int y)
{
    pair<int, int> ret = {0, 0};
    int tmp;

    if (n == 1)
    {
        tmp = check(arr, n, x, y);
        if (tmp == 0)
            ret.first++;
        else if (tmp == 1)
            ret.second++;
        return (ret);
    }
    ret.first = 0;
    ret.second = 0;
    tmp = check(arr, n, x, y);
    if (tmp == 0)
        ret.first++;
    else if (tmp == 1)
        ret.second++;
    else
    {
        pair<int, int> t;
        int nx[4] = { 0, n / 2, 0, n / 2 };
        int ny[4] = { 0, 0, n / 2, n / 2};
        for (int i = 0; i < 4; i++)
        {
            t = recursive(arr, n / 2, x + nx[i], y + ny[i]);
            ret.first += t.first;
            ret.second += t.second;
        }
    }
    return (ret);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    pair<int, int> answer = recursive(arr, n, 0, 0);
    cout << answer.first << '\n' << answer.second << '\n';
    return (0);
}