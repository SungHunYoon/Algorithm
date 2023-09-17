#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int k, w, h;
int arr[201][201];
bool visit[31][201][201];

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int knightX[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int knightY[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  
    cin >> k >> w >> h;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> arr[i][j];

    queue<pair<int, pair<int, int>>> q;
    visit[0][0][0] = true;
    q.push({0, {0, 0}});
    int answer = 1000000000;
    int cnt = 0;
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            int knight = q.front().first;
            pair<int, int> x = q.front().second;
            q.pop();
            if (x.first == w - 1 && x.second == h - 1)
            {
                answer = min(answer, cnt);
                break;
            }
            if (knight < k)
            {
                for (int j = 0; j < 8; j++)
                {
                    int dx, dy;
                    dx = x.first + knightX[j];
                    dy = x.second + knightY[j];
                    if (0 <= dx && dx < w && 0 <= dy && dy < h)
                    {
                        if (!visit[knight + 1][dy][dx] && arr[dy][dx] == 0)
                        {
                            visit[knight + 1][dy][dx] = true;
                            q.push({knight + 1, {dx, dy}});
                        }
                    }
                }
            }
            for (int j = 0; j < 4; j++)
            {
                int dx, dy;
                dx = x.first + nx[j];
                dy = x.second + ny[j];
                if (0 <= dx && dx < w && 0 <= dy && dy < h)
                {
                    if (!visit[knight][dy][dx] && arr[dy][dx] == 0)
                    {
                        visit[knight][dy][dx] = true;
                        q.push({knight, {dx, dy}});
                    }
                }
            }
        }
        if (answer != 1000000000)
            break;
        cnt++;
    }
    if (answer == 1000000000)
        cout << "-1\n";
    else
        cout << answer << '\n';
    return (0);
}