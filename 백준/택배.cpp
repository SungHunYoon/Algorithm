#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> arr[201];
int trace[201];
int d[201];
int answer[201][201];

void dijkstra(int index)
{
    d[index] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, index});
    while (!pq.empty())
    {
        int dis = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (d[cur] < dis)
            continue;
        for (int i = 0; i < arr[cur].size(); i++)
        {
            int nextDis = dis + arr[cur][i].first;
            int next = arr[cur][i].second;
            if (d[next] > nextDis)
            {
                trace[next] = cur;
                d[next] = nextDis;
                pq.push({-nextDis, next});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i == index)
            continue;
        int t = i;
        while (trace[t] != index)
            t = trace[t];
        answer[index][i] = t;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        arr[s].push_back({t, e});
        arr[e].push_back({t, s});
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            d[j] = 1000000000;
        dijkstra(i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (answer[i][j] == 0)
                cout << '-' << ' ';
            else
                cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
    return (0);
}