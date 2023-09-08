#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int arr[1001][1001];
int visit[1001][1001];
int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
                q.push({j, i});
            else if (arr[i][j] == 1)
                visit[i][j] = -1;
            else
                visit[i][j] = 0;
        }
    }
    int cnt = 0;
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            pair<int, int> x = q.front();
            q.pop();
            if (arr[x.second][x.first] != 0)
            {
                visit[x.second][x.first] = cnt;
                for (int j = 0; j < 4; j++)
                {
                    int dx, dy;
                    dx = x.first + nx[j];
                    dy = x.second + ny[j];
                    if (0 <= dx && dx < m && 0 <= dy && dy < n)
                    {
                        if (visit[dy][dx] == -1)
                        {
                            visit[dy][dx] = cnt;
                            q.push({dx, dy});
                        }
                    }
                }
            }
        }
        cnt++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << visit[i][j] << ' ';
        cout << '\n';
    }
    return (0);
}