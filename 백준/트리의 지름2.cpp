#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<pair<int, int>> arr[10001];
int d[10001];

void dijkstra(int index)
{
    d[index] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, index});
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int dis = -pq.top().first;
        pq.pop();
        if (d[cur] < dis)
            continue;
        for (int i = 0; i < arr[cur].size(); i++)
        {
            int next = arr[cur][i].second;
            int nextDis = arr[cur][i].first + dis;
            if (d[next] > nextDis)
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

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int src, dest, dis;
        cin >> src >> dest >> dis;
        arr[src].push_back({dis, dest});
        arr[dest].push_back({dis, src});
    }
    for (int i = 1; i <= n; i++)
        d[i] = 1000000000;
    dijkstra(1);
    int max = 0;
    int index = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] != 1000000000 && d[i] > max)
        {
            max = d[i];
            index = i;
        }
    }
    for (int i = 1; i <= n; i++)
        d[i] = 1000000000;
    dijkstra(index);
    max = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] != 1000000000 && d[i] > max)
            max = d[i];
    }
    cout << max << '\n';
    return (0);
}