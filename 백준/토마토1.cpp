#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int m, n, h;
int arr[101][101][101];
bool visit[101][101][101];
int nx[6] = { 1, -1, 0, 0, 0, 0};
int ny[6] = { 0, 0, 1, -1, 0, 0};
int nz[6] = { 0, 0, 0, 0, 1, -1};

typedef struct s_tomato
{
    int x;
    int y;
    int z;
} t_tomato;

int check()
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (arr[i][j][k] == 0)
                    return (0);
            }
        }
    }
    return (1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n >> h;
    queue<t_tomato> q;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1)
                    q.push({k, j, i});
                else if (arr[i][j][k] == -1)
                    visit[i][j][k] = true;
            }
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
            arr[t.z][t.y][t.x] = 1;
            for (int j = 0; j < 6; j++)
            {
                int dx = t.x + nx[j];
                int dy = t.y + ny[j];
                int dz = t.z + nz[j];
                if (0 <= dx && dx < m && 0 <= dy && dy < n && 0 <= dz && dz < h)
                {
                    if (!visit[dz][dy][dx] && arr[dz][dy][dx] == 0)
                    {
                        visit[dz][dy][dx] = true;
                        q.push({dx, dy, dz});
                    }
                }
            }
        }
        answer++;
    }
    if (check() == 1)
        cout << answer << '\n';
    else
        cout << "-1\n";
    return (0);
}