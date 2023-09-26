#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int n, m;
int arr[51][51];
int visit[51][51];
int room_cnt[2501];
set<pair<int, int>> room[2501];

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int bfs(int x, int y, int idx)
{
    queue<pair<int, int>> q;
    visit[y][x] = idx;
    q.push({x, y});
    int cnt = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int dx, dy;
            dx = p.first + nx[i];
            dy = p.second + ny[i];
            if (0 <= dx && dx < m && 0 <= dy && dy < n)
            {
                if (!visit[dy][dx])
                {
                    if (i == 0 && (arr[p.second][p.first] & 4) == 0)
                    {
                        visit[dy][dx] = idx;
                        q.push({dx, dy});
                    }
                    else if (i == 1 && (arr[p.second][p.first] & 1) == 0)
                    {
                        visit[dy][dx] = idx;
                        q.push({dx, dy});
                    }
                    else if (i == 2 && (arr[p.second][p.first] & 8) == 0)
                    {
                        visit[dy][dx] = idx;
                        q.push({dx, dy});
                    }
                    else if (i == 3 && (arr[p.second][p.first] & 2) == 0)
                    {
                        visit[dy][dx] = idx;
                        q.push({dx, dy});
                    }
                    else
                        room[idx].insert({dx, dy});
                }
            }
        }
    }
    return (cnt);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int maxCnt = 0;
    int idx = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j])
            {
                room_cnt[idx] = bfs(j, i, idx);
                maxCnt = max(maxCnt, room_cnt[idx]);
                idx++;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= idx; i++)
    {
        for (set<pair<int, int>>::iterator iter = room[i].begin(); iter != room[i].end(); iter++)
        {
            int add = visit[iter->second][iter->first];
            if (add != i)
                sum = max(sum, room_cnt[i] + room_cnt[add]);
        }
    }
    cout << idx - 1 << '\n';
    cout << maxCnt << '\n';
    cout << sum << '\n';
    return (0);
}