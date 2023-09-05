#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int bfs(queue<pair<int, int>> q, vector<vector<int>> arr, int n, int m)
{
    while (!q.empty())
    {
        pair<int, int> x = q.front();
        q.pop();
        if (x.first + 1 < n && arr[x.first + 1][x.second] == 0)
        {
            arr[x.first + 1][x.second] = 2;
            q.push({x.first + 1, x.second});
        }
        if (x.first - 1 >= 0 && arr[x.first - 1][x.second] == 0)
        {
            arr[x.first - 1][x.second] = 2;
            q.push({x.first - 1, x.second});
        }
        if (x.second + 1 < m && arr[x.first][x.second + 1] == 0)
        {
            arr[x.first][x.second + 1] = 2;
            q.push({x.first, x.second + 1});
        }
        if (x.second - 1 >= 0 && arr[x.first][x.second - 1] == 0)
        {
            arr[x.first][x.second - 1] = 2;
            q.push({x.first, x.second - 1});
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
                cnt++;
        }
    }
    return (cnt);
}

int recursive(queue<pair<int, int>> &q, vector<vector<int>> &arr, int n, int m, int cnt)
{
    if (cnt == 3)
        return (bfs(q, arr, n, m));
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][j] = 1;
                int tmp = recursive(q, arr, n, m, cnt + 1);
                if (tmp > ret)
                    ret = tmp;
                arr[i][j] = 0;
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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
                q.push({i, j});
        }
    }
    cout << recursive(q, arr, n, m, 0) << '\n';
    return (0);
}