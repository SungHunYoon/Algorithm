#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }
    
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    queue<pair<int, pair<int, int>>> q;
    int cnt = 0;
    int nx[4] = {0, 0, 1, -1};
    int ny[4] = {1, -1, 0, 0};
    visit[0][0] = true;
    q.push({cnt, {0, 0}});
    while (!q.empty())
    {
        cnt = q.front().first;
        pair<int, int> f = q.front().second;
        q.pop();
        if (f.first == n - 1 && f.second == m - 1)
        {
            cnt++;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int y = f.first + ny[i];
            int x = f.second + nx[i];
            if (0 <= x && x < m && 0 <= y && y < n && arr[y][x] == 1)
            {
                if (visit[y][x])
                    continue;
                visit[y][x] = true;
                q.push({cnt + 1, {y, x}});
            }
        }
    }
    cout << cnt << '\n';
    return (0);
}