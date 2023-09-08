#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int snake[101];
int ladder[101];
bool visit[101];

queue<int> q;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        ladder[s] = e;
    }
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        snake[s] = e;
    }

    q.push(1);
    visit[1] = true;

    int cnt = 0;
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            int x = q.front();
            q.pop();
            if (x == 100)
            {
                cout << cnt << '\n';
                return (0);
            }
            for (int j = 1; j <= 6; j++)
            {
                int dx = x + j;
                if (ladder[dx] != 0)
                    dx = ladder[dx];
                else if (snake[dx] != 0)
                    dx = snake[dx];
                if (dx < 101 && !visit[dx])
                {
                    visit[dx] = true;
                    q.push(dx);
                }
            }
        }
        cnt++;
    }
    return (0);
}