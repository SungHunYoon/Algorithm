#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int arr[10][10];
int mapL[20];
int mapR[20];
int answer[2];

void dfs(int x, int y, int cnt)
{
    if (x >= n)
    {
        if (x % 2 == 1)
            x = 0;
        else
            x = 1;
        y++;
    }
    if (y >= n)
    {
        answer[x] = max(answer[x], cnt);
        return;
    }
    if (arr[y][x] == 1 && mapL[x - y + n - 1] == 0 && mapR[x + y] == 0)
    {
        mapL[x - y + n - 1] = 1;
        mapR[x + y] = 1;
        dfs(x + 2, y, cnt + 1);
        mapL[x - y + n - 1] = 0;
        mapR[x + y] = 0;
    }
    dfs(x + 2, y, cnt);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    dfs(0, 0, 0);
    dfs(1, 0, 0);
    cout << answer[0] + answer[1] << '\n';
    return (0);
}