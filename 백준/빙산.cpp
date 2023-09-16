#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int arr[301][301];

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int check(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int dx, dy;
        dx = x + nx[i];
        dy = y + ny[i];
        if  (arr[dy][dx] == 0)
            cnt++;
    }
    return (cnt);
}

void recursive(int tmp[][301], bool visit[][301], int x, int y)
{
    if (x < 0 || y < 0 || x >= m || y >= n)
        return;
    else if (tmp[y][x] == 0)
        return;
    else if (visit[y][x])
        return;
    visit[y][x] = true;
    recursive(tmp, visit, x + 1, y);
    recursive(tmp, visit, x - 1, y);
    recursive(tmp, visit, x, y + 1);
    recursive(tmp, visit, x, y - 1);
}

int melt()
{
    int tmp[301][301] = { 0, };
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            tmp[i][j] = arr[i][j] - check(j, i);
            if (tmp[i][j] < 0)
                tmp[i][j] = 0;
        }
    }
    bool visit[301][301] = { false, };
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            arr[i][j] = tmp[i][j];
            if (tmp[i][j] != 0 && !visit[i][j])
            {
                recursive(tmp, visit, j, i);
                cnt++;
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
  
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int answer = 0;
    while (1)
    {
        int cnt = melt();
        answer++;
        if (cnt == 0)
        {
            answer = 0;
            break;
        }
        else if (cnt >= 2)
            break;
    }
    cout << answer << '\n';
    return (0);
}