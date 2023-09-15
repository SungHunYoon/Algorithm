#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
bool visit[100050];
int trace[100050];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> k;
    for (int i = 0; i < 100050; i++)
        trace[i] = -1;
    queue<int> q;
    visit[n] = true;
    q.push(n);
    int answer = 0;
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            int x = q.front();
            q.pop();
            if (x == k)
            {
                cout << answer << '\n';
                vector<int> a;
                a.push_back(k);
                while (trace[k] != -1)
                {
                    a.push_back(trace[k]);
                    k = trace[k];
                }
                for (int i = a.size() - 1; i >= 0; i--)
                    cout << a[i] << ' ';
                cout << '\n';
                return (0);
            }
            int dx;
            dx = x * 2;
            if (dx < 100050 && !visit[dx])
            {
                visit[dx] = true;
                trace[dx] = x;
                q.push(dx);
            }
            dx = x + 1;
            if (dx < 100050 && !visit[dx])
            {
                visit[dx] = true;
                trace[dx] = x;
                q.push(dx);
            }
            dx = x - 1;
            if (dx >= 0 && !visit[dx])
            {
                visit[dx] = true;
                trace[dx] = x;
                q.push(dx);
            }
        }
        answer++;
    }
    return (0);
}