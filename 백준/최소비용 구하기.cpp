#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int s, e;
int d[1001];
vector<pair<int, int>> arr[1001];

void dijkstra(int index)
{
    d[index] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, index});
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int time = -pq.top().first;
        pq.pop();
        if (d[cur] < time)
            continue;
        for (int i = 0; i < arr[cur].size(); i++)
        {
            int next = arr[cur][i].second;
            int nextTime = arr[cur][i].first + time;
            if (d[next] > nextTime)
            {
                d[next] = nextTime;
                pq.push({-nextTime, next});
            }
        }
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
        int start, end, time;
        cin >> start >> end >> time;
        arr[start].push_back({time, end});
    }
    cin >> s >> e;
    for (int i = 1; i <= n; i++)
        d[i] = 1000000000;
    dijkstra(s);
    cout << d[e] << '\n';
    return (0);
}