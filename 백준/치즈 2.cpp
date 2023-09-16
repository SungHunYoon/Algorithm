#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int arr[101][101];

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                cnt++;
        }
    }

    int answer = cnt;
    int time = 0;
    while (cnt != 0)
    {
        queue<pair<int, int>> q;
        bool visit[101][101] = { false, };
        visit[0][0] = true;
        q.push({0, 0});
        while (!q.empty())
        {
            pair<int, int> x = q.front();
            q.pop();
            if (arr[x.second][x.first] == 1)
            {
                arr[x.second][x.first] = 0;
                cnt--;
                continue;
            }
            for (int i = 0; i < 4; i++)
            {
                int dx, dy;
                dx = x.first + nx[i];
                dy = x.second + ny[i];
                if (0 <= dx && dx < m && 0 <= dy && dy < n)
                {
                    if (!visit[dy][dx])
                    {
                        visit[dy][dx] = true;
                        q.push({dx, dy});
                    }
                }
            }
        }
        time++;
        if (cnt == 0)
            break;
        answer = cnt;
    }
    cout << time << '\n' << answer << '\n';
    return (0);
}