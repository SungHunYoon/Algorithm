#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int check(vector<vector<int>> &arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != 0)
                return (0);
        }
    }
    return (1);
}

void melt(vector<vector<int>> &arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] >= 3)
                arr[i][j] = 0;
            else if (arr[i][j] == 2)
                arr[i][j] = 1;
        }
    }
}

int solve(vector<vector<int>> &arr, int n, int m)
{
    int cnt = 0;
    while (check(arr, n, m) == 0)
    {
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty())
        {
            pair<int, int> x = q.front();
            q.pop();
            if (x.first + 1 < n)
            {
                if (arr[x.first + 1][x.second] == 0)
                {
                    q.push({x.first + 1, x.second});
                    arr[x.first + 1][x.second] = 3;
                }
                else
                    arr[x.first + 1][x.second]++;
            }
            if (x.first - 1 >= 0)
            {
                if (arr[x.first - 1][x.second] == 0)
                {
                    q.push({x.first - 1, x.second});
                    arr[x.first - 1][x.second] = 3;
                }
                else
                    arr[x.first - 1][x.second]++;
            }
            if (x.second + 1 < m)
            {
                if (arr[x.first][x.second + 1] == 0)
                {
                    q.push({x.first, x.second + 1});
                    arr[x.first][x.second + 1] = 3;
                }
                else
                    arr[x.first][x.second + 1]++;
            }
            if (x.second - 1 >= 0)
            {
                if (arr[x.first][x.second - 1] == 0)
                {
                    q.push({x.first, x.second - 1});
                    arr[x.first][x.second - 1] = 3;
                }
                else
                    arr[x.first][x.second - 1]++;
            }
        }
        melt(arr, n, m);
        cnt++;
    }
    return (cnt);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    cout << solve(arr, n, m) << '\n';
    return (0);
}