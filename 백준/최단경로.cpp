#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int v, e, k;
int d[20001];
vector<pair<int, int>> arr[20001];

void dijkstra(int index)
{
    d[index] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, index});
    while (!pq.empty())
    {
        int current = pq.top().second;
        int dis = -(pq.top().first);
        pq.pop();
        if (d[current] < dis) continue;
        for (int i = 0; i < arr[current].size(); i++)
        {
            int next = arr[current][i].first;
            int nextDis = dis + arr[current][i].second;
            if (nextDis < d[next])
            {
                d[next] = nextDis;
                pq.push({-nextDis, next});
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> v >> e >> k;
    for (int i = 0; i < e; i++)
    {
        int src, dest, dis;
        cin >> src >> dest >> dis;
        arr[src].push_back({dest, dis});
    }
    for (int i = 1; i <= v; i++)
        d[i] = 1000000000;
    dijkstra(k);
    for (int i = 1; i <= v; i++)
    {
        if (d[i] == 1000000000)
            cout << "INF\n";
        else
            cout << d[i] << '\n';
    }
    return (0);
}