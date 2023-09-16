#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int r, c;
int arr[51][51];
pair<int, int> e;
pair<int, int> s;

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  
    cin >> r >> c;
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char c;
            cin >> c;
            if (c == 'D')
            {
                arr[i][j] = 0;
                e = {j, i};
            }
            else if (c == '.')
                arr[i][j] = 0;
            else if (c == '*')
            {
                q.push({2, {j, i}});
                arr[i][j] = 2;
            }
            else if (c == 'X')
                arr[i][j] = 1;
            else if (c == 'S')
            {
                arr[i][j] = 3;
                s = {j, i};
            }
        }
    }

    int answer = 0;
    q.push({3, s});
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            int kind = q.front().first;
            pair<int, int> x = q.front().second;
            q.pop();

            if (kind == 2)
            {
                for (int i = 0; i < 4; i++)
                {
                    int dx, dy;
                    dx = x.first + nx[i];
                    dy = x.second + ny[i];
                    if (0 <= dx && dx < c && 0 <= dy && dy < r)
                    {
                        if ((arr[dy][dx] == 0 || arr[dy][dx] == 3) && !(dx == e.first && dy == e.second))
                        {
                            arr[dy][dx] = 2;
                            q.push({arr[dy][dx], {dx, dy}});
                        }
                    }
                }
            }
            else if (kind == 3)
            {
                if (x.first == e.first && x.second == e.second)
                {
                    cout << answer << '\n';
                    return (0);
                }
                for (int i = 0; i < 4; i++)
                {
                    int dx, dy;
                    dx = x.first + nx[i];
                    dy = x.second + ny[i];
                    if (0 <= dx && dx < c && 0 <= dy && dy < r)
                    {
                        if (arr[dy][dx] == 0)
                        {
                            arr[x.second][x.first] = 3;
                            arr[dy][dx] = 3;
                            q.push({arr[dy][dx], {dx, dy}});
                        }
                    }
                }
            }
        }
        answer++;
    }
    cout << "KAKTUS\n";
    return (0);
}