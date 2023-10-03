#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

pair<int, int> src;
pair<int, int> dst;
int n;
pair<int, int> arr[4003];
bool table[10000];

int d[4003];
vector<pair<int, int>> e[4003];

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
        for (int i = 0; i < e[cur].size(); i++)
        {
            int nextDis = dis + e[cur][i].first;
            int next = e[cur][i].second;
            if (d[next] > nextDis)
            {
                d[next] = nextDis;
                pq.push({-nextDis, next});
            }
        }
    }
}

int getDistance(int x1, int y1, int x2, int y2)
{
    return sqrt((pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> src.first >> src.second >> dst.first >> dst.second;
    cin >> n;
    arr[0] = src;
    for (int i = 1; i <= n; i++)
        cin >> arr[i].first >> arr[i].second;
    arr[n + 1] = dst;

    table[0] = true;
    table[1] = true;
    for (int i = 0; i < 10001; i++)
    {
        if (table[i])
            continue;
        for (int j = i * 2; j < 10001; j += i)
            table[j] = true;
    }

    int index = 0;
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = i + 1; j < n + 2; j++)
        {
            int dis = getDistance(arr[i].first, arr[i].second, arr[j].first, arr[j].second);
            if (!table[dis])
            {
                e[i].push_back({dis, j});
                e[j].push_back({dis, i});
            }
        }
    }

    for (int i = 0; i < n + 2; i++)
        d[i] = 1000000000;
    dijkstra(0);
    if (d[n + 1] != 1000000000)
        cout << d[n + 1] << '\n';
    else
        cout << "-1\n";
    return (0);
}