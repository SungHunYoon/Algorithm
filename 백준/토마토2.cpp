#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int m, n;
int arr[1001][1001];
bool visit[1001][1001];
int nx[4] = { 1, -1, 0, 0 };
int ny[4] = { 0, 0, 1, -1 };

typedef struct s_tomato
{
    int x;
    int y;
} t_tomato;

int check()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
                return (0);
        }
    }
    return (1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;
    queue<t_tomato> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                q.push({j, i});
            else if (arr[i][j] == -1)
                visit[i][j] = true;
        }
    }

    int answer = 0;
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            t_tomato t = q.front();
            q.pop();
            arr[t.y][t.x] = 1;
            for (int j = 0; j < 4; j++)
            {
                int dx = t.x + nx[j];
                int dy = t.y + ny[j];
                if (0 <= dx && dx < m && 0 <= dy && dy < n)
                {
                    if (!visit[dy][dx] && arr[dy][dx] == 0)
                    {
                        visit[dy][dx] = true;
                        q.push({dx, dy});
                    }
                }
            }
        }
        answer++;
    }
    if (check() == 1)
        cout << answer - 1 << '\n';
    else
        cout << "-1\n";
    return (0);
}