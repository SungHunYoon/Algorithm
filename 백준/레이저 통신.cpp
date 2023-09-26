#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int w, h;
int arr[101][101];
int visit[5][101][101];
pair<int, int> src;
pair<int, int> dst;

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> w >> h;
    int check = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char c;
            cin >> c;
            if (c == 'C')
            {
                if (check == 0)
                {
                    src = {j, i};
                    check = 1;
                }
                else
                    dst = {j, i};
            }
            else if (c == '*')
                arr[i][j] = 1;
        }
    }
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < h; j++)
            for (int k = 0; k < w; k++)
                visit[i][j][k] = 1000000000;

    queue<pair<pair<int, int>, pair<int, int>>> q;
    visit[1][src.second][src.first] = 0;
    visit[2][src.second][src.first] = 0;
    visit[3][src.second][src.first] = 0;
    visit[4][src.second][src.first] = 0;
    q.push({{0, 0}, src});
    int answer = 1000000000;
    while (!q.empty())
    {
        pair<int, int> dirCnt = q.front().first;
        pair<int, int> x = q.front().second;
        q.pop();
        if (x.first == dst.first && x.second == dst.second)
            answer = min(answer, dirCnt.second);
        for (int i = 0; i < 4; i++)
        {
            int dx, dy;
            dx = x.first + nx[i];
            dy = x.second + ny[i];
            if (0 <= dx && dx < w && 0 <= dy && dy < h)
            {
                if (visit[dirCnt.first][dy][dx] > dirCnt.second && arr[dy][dx] == 0)
                {
                    if (dirCnt.first == 1)
                    {
                        if (i == 0)
                        {
                            q.push({{i + 1, dirCnt.second}, {dx, dy}});
                            visit[i + 1][dy][dx] = dirCnt.second;
                        }
                        else if (i == 2 || i == 3)
                        {
                            q.push({{i + 1, dirCnt.second + 1}, {dx, dy}});
                            visit[i + 1][dy][dx] = dirCnt.second + 1;
                        }
                    }
                    else if (dirCnt.first == 2)
                    {
                        if (i == 1)
                        {
                            q.push({{i + 1, dirCnt.second}, {dx, dy}});
                            visit[i + 1][dy][dx] = dirCnt.second;
                        }
                        else if (i == 2 || i == 3)
                        {
                            q.push({{i + 1, dirCnt.second + 1}, {dx, dy}});
                            visit[i + 1][dy][dx] = dirCnt.second + 1;
                        }
                    }
                    else if (dirCnt.first == 3)
                    {
                        if (i == 0 || i == 1)
                        {
                            q.push({{i + 1, dirCnt.second + 1}, {dx, dy}});
                            visit[i + 1][dy][dx] = dirCnt.second + 1;
                        }
                        else if (i == 2)
                        {
                            q.push({{i + 1, dirCnt.second}, {dx, dy}});
                            visit[i + 1][dy][dx] = dirCnt.second;
                        }
                    }
                    else if (dirCnt.first == 4)
                    {
                        if (i == 0 || i == 1)
                        {
                            q.push({{i + 1, dirCnt.second + 1}, {dx, dy}});
                            visit[i + 1][dy][dx] = dirCnt.second + 1;
                        }
                        else if (i == 3)
                        {
                            q.push({{i + 1, dirCnt.second}, {dx, dy}});
                            visit[i + 1][dy][dx] = dirCnt.second;
                        }
                    }
                    else
                    {
                        q.push({{i + 1, dirCnt.second}, {dx, dy}});
                        visit[i + 1][dy][dx] = dirCnt.second;
                    }
                }
            }
        }
    }
    cout << answer << '\n';
    return (0);
}