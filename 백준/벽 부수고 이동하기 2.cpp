#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;
int arr[1001][1001];
bool visit[11][1001][1001];

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }
    queue<pair<int, pair<int, int>>> q;
    visit[0][0][0] = true;
    q.push({0, {0, 0}});
    int dis = 1;
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            int break_cnt = q.front().first;
            pair<int, int> x = q.front().second;
            q.pop();
            if (x.first == m - 1 && x.second == n - 1)
            {
                cout << dis << '\n';
                return (0);
            }
            for (int j = 0; j < 4; j++)
            {
                int dx, dy;
                dx = x.first + nx[j];
                dy = x.second + ny[j];
                if (0 <= dx && dx < m && 0 <= dy && dy < n)
                {
                    if (arr[dy][dx] == 1 && break_cnt < k)
                    {
                        if (!visit[break_cnt + 1][dy][dx])
                        {
                            visit[break_cnt + 1][dy][dx] = true;
                            q.push({break_cnt + 1, {dx, dy}});
                        }
                    }
                    if (!visit[break_cnt][dy][dx] && arr[dy][dx] == 0)
                    {
                        visit[break_cnt][dy][dx] = true;
                        q.push({break_cnt, {dx, dy}});
                    }
                }
            }
        }
        dis++;
    }
    cout << "-1\n";
    return (0);
}