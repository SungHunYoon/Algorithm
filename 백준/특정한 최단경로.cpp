#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, e;
int v1, v2;
vector<pair<int, int>> arr[801];
int d[801];

void dijkstra(int *dis, int index)
{
    dis[index] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({index, 0});
    while (!pq.empty())
    {
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();
        if (dis[current] < distance) continue;
        for (int i = 0; i < arr[current].size(); i++)
        {
            int next = arr[current][i].first;
            int nextDis = distance + arr[current][i].second;
            if (nextDis < dis[next])
            {
                dis[next] = nextDis;
                pq.push({next, -nextDis});
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int src, dest, dis;
        cin >> src >> dest >> dis;
        arr[src].push_back({dest, dis});
        arr[dest].push_back({src, dis});
    }
    cin >> v1 >> v2;
    long long answer = 0;
    for (int i = 1; i <= n; i++)
        d[i] = 1000000000;
    dijkstra(d, 1);
    answer += d[v1];
    for (int i = 1; i <= n; i++)
        d[i] = 1000000000;
    dijkstra(d, v1);
    answer += d[v2];
    for (int i = 1; i <= n; i++)
        d[i] = 1000000000;
    dijkstra(d, v2);
    answer += d[n];
    if (answer > 1000000000)
        answer = -1;
    cout << answer << '\n';
    return (0);
}