#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
char arr[1001][1001];
int visit[1001][1001];

int dfs(int x, int y, int index)
{
    if (visit[y][x] != 0)
    {
        if (visit[y][x] == index)
            return (1);
        else
            return (0);
    }
    visit[y][x] = index;
    int ret = 1;
    if (arr[y][x] == 'D')
        ret = min(dfs(x, y + 1, index), ret);
    else if (arr[y][x] == 'L')
        ret = min(dfs(x - 1, y, index), ret);
    else if (arr[y][x] == 'R')
        ret = min(dfs(x + 1, y, index), ret);
    else
        ret = min(dfs(x, y - 1, index), ret);
    return (ret);
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
    int index = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j])
            {
                if (dfs(j, i, index) == 1)
                    answer++;
                index++;
            }
        }
    }
    cout << answer << '\n';
    return (0);
}