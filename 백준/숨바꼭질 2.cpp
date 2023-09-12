#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
int visit[100050];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    queue<int> q;
    visit[n] = 1;
    q.push(n);
    int second = 0;
    int cnt = 0;
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            int x = q.front();
            q.pop();
            if (x == k)
                cnt++;
            int dx;
            dx = 2 * x;
            if (0 <= dx && dx < 100050 && (visit[dx] == 0 || visit[dx] >= second))
            {
                visit[dx] = second;
                q.push(dx);
            }
            dx = x + 1;
            if (0 <= dx && dx < 100050 && (visit[dx] == 0 || visit[dx] >= second))
            {
                visit[dx] = second;
                q.push(dx);
            }
            dx = x - 1;
            if (0 <= dx && dx < 100050 && (visit[dx] == 0 || visit[dx] >= second))
            {
                visit[dx] = second;
                q.push(dx);
            }
        }
        if (cnt != 0)
            break;
        second++;
    }
    cout << second << '\n' << cnt << '\n';
    return (0);
}