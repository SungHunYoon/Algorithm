#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> arr[1001];
int src, dest;
int d[1001];
int trace[1001];

void dijkstra(int index)
{
    d[index] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, index});
    while (!pq.empty())
    {
        int time = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (d[cur] < time)
            continue;
        for (int i = 0; i < arr[cur].size(); i++)
        {
            int nextTime = arr[cur][i].first + time;
            int next = arr[cur][i].second;
            if (d[next] > nextTime)
            {
                trace[next] = cur;
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
        int s, e, t;
        cin >> s >> e >> t;
        arr[s].push_back({t, e});
    }
    cin >> src >> dest;
    for (int i = 1; i <= n; i++)
        d[i] = 1000000000;
    dijkstra(src);
    cout << d[dest] << '\n';
    vector<int> answer;
    answer.push_back(dest);
    while (trace[dest] != src)
    {
        answer.push_back(trace[dest]);
        dest = trace[dest];
    }
    answer.push_back(trace[dest]);
    cout << answer.size() << '\n';
    for (int i = answer.size() - 1; i >= 0; i--)
        cout << answer[i] << ' ';
    cout << '\n';
    return (0);
}