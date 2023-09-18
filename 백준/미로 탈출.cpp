#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
pair<int, int> s;
pair<int, int> e;
int arr[1001][1001];
bool visit[2][1001][1001];

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    cin >> s.second >> s.first;
    cin >> e.second >> e.first;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    queue<pair<int, pair<int, int>>> q;
    visit[0][s.second][s.first] = true;
    q.push({0, {s.first, s.second}});
    int answer = 1000000000;
    int cnt = 0;
    int flag = 0;
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            int break_cnt = q.front().first;
            pair<int, int> x = q.front().second;
            q.pop();
            if (x.first == e.first && x.second == e.second)
            {
                answer = min(answer, cnt);
                flag = 1;
                break;
            }
            for (int j = 0; j < 4; j++)
            {
                int dx, dy;
                dx = x.first + nx[j];
                dy = x.second + ny[j];
                if (1 <= dx && dx <= m && 1 <= dy && dy <= n)
                {
                    if (break_cnt < 1)
                    {
                        if (!visit[break_cnt + 1][dy][dx] && arr[dy][dx] == 1)
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
        if (flag == 1)
            break;
        cnt++;
    }
    if (answer == 1000000000)
        cout << "-1\n";
    else
        cout << answer << '\n';
    return (0);
}