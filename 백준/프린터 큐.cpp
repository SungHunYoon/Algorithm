#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        int m;
        cin >> n >> m;
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        for (int j = 0; j < n; j++)
        {
            int p;
            cin >> p;
            pq.push(p);
            q.push({j, p});
        }
        int rank = 1;
        while (!q.empty())
        {
            if (q.front().second == pq.top())
            {
                if (q.front().first == m)
                {
                    cout << rank << '\n';
                    break;
                }
                q.pop();
                pq.pop();
                rank++;
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }
    }

    return (0);
}