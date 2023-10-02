#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int t, n, m;

void dijkstra(vector<pair<int, int>> *arr, int *d, int *t, int index)
{
    d[index] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, index});
    while (!pq.empty())
    {
        int dis = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < arr[cur].size(); i++)
        {
            int nextDis = arr[cur][i].first + dis;
            int next = arr[cur][i].second;
            if (d[next] > nextDis)
            {
                d[next] = nextDis;
                pq.push({-nextDis, next});
                t[next] = cur;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int k = 0; k < t; k++)
    {
        vector<pair<int, int>> arr[21];
        int d[21];
        int t[21] = { 0, };
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[x + 1].push_back({z, y + 1});
            arr[y + 1].push_back({z, x + 1});
        }
        for (int i = 1; i <= m; i++)
            d[i] = 1000000000;
        dijkstra(arr, d, t, 1);
        cout << "Case #" << k + 1 << ": ";
        if (d[m] == 1000000000)
            cout << "-1\n";
        else
        {
            int index = m;
            vector<int> answer;
            answer.push_back(m - 1);
            while (t[index])
            {
                answer.push_back(t[index] - 1);
                index = t[index];
            }
            for (int i = answer.size() - 1; i >= 0; i--)
                cout << answer[i] << ' ';
            cout << '\n';
        }
    }
    return (0);
}