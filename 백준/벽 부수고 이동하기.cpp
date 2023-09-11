#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int arr[1001][1001];
bool visit[1001][1001];
bool bvisit[1001][1001];
int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

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
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }
    int answer = 0;
    queue<pair<int, pair<int, int>>> q;
    visit[0][0] = true;
    q.push({1, {0, 0}});
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            int isBreak = q.front().first;
            pair<int, int> x = q.front().second;
            q.pop();
            if (x.first + 1 == m && x.second + 1 == n)
            {
                cout << answer + 1 << '\n';
                return (0);
            }
            if (arr[x.second][x.first] == 1)
            {
                if (isBreak == 0)
                    continue;
                else
                    isBreak = 0;
            }
            for (int j = 0; j < 4; j++)
            {
                int dx, dy;
                dx = x.first + nx[j];
                dy = x.second + ny[j];
                if (0 <= dx && dx < m && 0 <= dy && dy < n)
                {
                    if (isBreak == 1)
                    {
                        if (!visit[dy][dx])
                        {
                            bvisit[dy][dx] = true;
                            visit[dy][dx] = true;
                            q.push({isBreak, {dx, dy}});
                        }
                    }
                    else
                    {
                        if (!bvisit[dy][dx])
                        {
                            bvisit[dy][dx] = true;
                            q.push({isBreak, {dx, dy}});
                        }
                    }
                }
            }
        }
        answer++;
    }
    cout << "-1\n";
    return (0);
}