#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int n, m;
vector<pair<int, int>> arr[1001];
int d[1001];
int trace[1001];

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
                trace[next] = cur;
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

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        arr[s].push_back({t, e});
        arr[e].push_back({t, s});
    }
    for (int i = 1; i <= n; i++)
        d[i] = 1000000000;
    dijkstra(1);
    set<pair<int, int>> answer;
    for (int i = 2; i <= n; i++)
    {
        int t = trace[i];
        answer.insert({min(t, i), max(t, i)});
        while (t != 1)
        {
            answer.insert({min(t, trace[t]), max(t, trace[t])});
            t = trace[t];
        }
    }
    cout << answer.size() << '\n';
    for (set<pair<int, int>>::iterator iter = answer.begin(); iter != answer.end(); iter++)
        cout << iter->first << ' ' << iter->second << '\n';
    return (0);
}