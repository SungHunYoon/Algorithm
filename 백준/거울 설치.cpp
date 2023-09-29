#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int arr[51][51];
int visit[5][51][51];
pair<int, int> src;
pair<int, int> dst;

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if (c == '*')
                arr[i][j] = 1;
            else if (c == '#')
            {
                if (check == 0)
                {
                    src = {j, i};
                    check = 1;
                }
                else
                    dst = {j, i};
            }
            else if (c == '!')
                arr[i][j] = 2;
        }
    }

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                visit[i][j][k] = 1000000000;

    int answer = 1000000000;
    queue<pair<pair<int, int>, pair<int, int>>> q;
    visit[1][src.second][src.first] = 0;
    visit[2][src.second][src.first] = 0;
    visit[3][src.second][src.first] = 0;
    visit[4][src.second][src.first] = 0;
    q.push({{0, 0}, {src.first, src.second}});
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
            if (0 <= dx && dx < n && 0 <= dy && dy < n)
            {
                if (visit[i + 1][dy][dx] >= dirCnt.second && arr[dy][dx] != 1)
                {
                    if (dirCnt.first == 1)
                    {
                        if (i == 0)
                        {
                            visit[i + 1][dy][dx] = dirCnt.second;
                            q.push({{i + 1, dirCnt.second}, {dx, dy}});
                        }
                        else if ((i == 2 || i == 3) && arr[x.second][x.first] == 2)
                        {
                            visit[i + 1][dy][dx] = dirCnt.second + 1;
                            q.push({{i + 1, dirCnt.second + 1}, {dx, dy}});
                        }
                    }
                    else if (dirCnt.first == 2)
                    {
                        if (i == 1)
                        {
                            visit[i + 1][dy][dx] = dirCnt.second;
                            q.push({{i + 1, dirCnt.second}, {dx, dy}});
                        }
                        else if ((i == 2 || i == 3) && arr[x.second][x.first] == 2)
                        {
                            visit[i + 1][dy][dx] = dirCnt.second + 1;
                            q.push({{i + 1, dirCnt.second + 1}, {dx, dy}});
                        }
                    }
                    else if (dirCnt.first == 3)
                    {
                        if (i == 2)
                        {
                            visit[i + 1][dy][dx] = dirCnt.second;
                            q.push({{i + 1, dirCnt.second}, {dx, dy}});
                        }
                        else if ((i == 0 || i == 1) && arr[x.second][x.first] == 2)
                        {
                            visit[i + 1][dy][dx] = dirCnt.second + 1;
                            q.push({{i + 1, dirCnt.second + 1}, {dx, dy}});
                        }
                    }
                    else if (dirCnt.first == 4)
                    {
                        if (i == 3)
                        {
                            visit[i + 1][dy][dx] = dirCnt.second;
                            q.push({{i + 1, dirCnt.second}, {dx, dy}});
                        }
                        else if ((i == 0 || i == 1) && arr[x.second][x.first] == 2)
                        {
                            visit[i + 1][dy][dx] = dirCnt.second + 1;
                            q.push({{i + 1, dirCnt.second + 1}, {dx, dy}});
                        }
                    }
                    else
                    {
                        visit[i + 1][dy][dx] = dirCnt.second;
                        q.push({{i + 1, dirCnt.second}, {dx, dy}});
                    }
                }
            }
        }
    }
    cout << answer << '\n';
    return (0);
}