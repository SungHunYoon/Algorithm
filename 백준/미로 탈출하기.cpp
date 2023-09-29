#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
char arr[501][501];
int visit[501][501];

int dfs(int x, int y)
{
    if (x < 0 || y < 0 || x >= m || y >= n)
        return (1);
    else if (visit[y][x] != 1000000000)
        return (visit[y][x]);
    visit[y][x] = 0;
    int dx = x;
    int dy = y;
    if (arr[y][x] == 'U')
        dy -= 1;
    else if (arr[y][x] == 'D')
        dy += 1;
    else if (arr[y][x] == 'L')
        dx -= 1;
    else
        dx += 1;
    if (dfs(dx, dy) == 1)
        visit[y][x] = 1;
    return (visit[y][x]);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            visit[i][j] = 1000000000;
        }
    }
    
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visit[i][j] == 1000000000)
            {
                if (dfs(j, i) == 1)
                    answer++;
            }
            else if (visit[i][j] == 1)
                answer++;
        }
    }
    cout << answer << '\n';
    return (0);
}