#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int r, c;
char arr[21][21];
bool visit[21][21];
bool table[27];
int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int recursive(int cnt, int curR, int curC)
{
    if (curR < 0 || curR >= r || curC < 0 || curC >= c)
        return (cnt);
    if (visit[curR][curC])
        return (cnt);
    if (table[arr[curR][curC] - 'A'])
        return (cnt);
    visit[curR][curC] = true;
    table[arr[curR][curC] - 'A'] = true;
    int ret = 0;
    for (int i = 0; i < 4; i++)
    {
        int dx, dy;
        dx = curC + nx[i];
        dy = curR + ny[i];
        int tmp = recursive(cnt + 1, dy, dx);
        if (tmp > ret)
            ret = tmp;
    }
    visit[curR][curC] = false;
    table[arr[curR][curC] - 'A'] = false;
    return (ret);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> arr[i][j];
    cout << recursive(0, 0, 0) << '\n';
    return (0);
}