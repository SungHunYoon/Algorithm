#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int n, m;
int arr[1001][1001];
int visit[1001][1001];
int table[1000001];

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int dfs(int x, int y, int index)
{
    if (x < 0 || y < 0 || x >= m || y >= n)
        return (0);
    else if (visit[y][x])
        return (0);
    else if (arr[y][x] == 1)
        return (0);
    visit[y][x] = index;
    int ret = 1;
    ret += dfs(x + 1, y, index);
    ret += dfs(x - 1, y, index);
    ret += dfs(x, y + 1, index);
    ret += dfs(x, y - 1, index);
    return (ret);
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
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }
    
    int index = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j] && arr[i][j] == 0)
            {
                table[index] = dfs(j, i, index);
                index++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                int sum = 1;
                set<int> s;
                for (int k = 0; k < 4; k++)
                {
                    int dx, dy;
                    dx = j + nx[k];
                    dy = i + ny[k];
                    if (0 <= dx && dx < m && 0 <= dy && dy < n)
                    {
                        if (s.find(visit[dy][dx]) == s.end())
                        {
                            s.insert(visit[dy][dx]);
                            sum += table[visit[dy][dx]];
                        }
                    }
                }
                cout << sum % 10;
            }
            else
                cout << '0';
        }
        cout << '\n';
    }
    return (0);
}