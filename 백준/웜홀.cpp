#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int n, m, w;

int bf(vector<pair<int, pair<int, int>>> &arr, int *d)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            int time = arr[j].first;
            int cur = arr[j].second.first;
            int next = arr[j].second.second;
            if (d[cur] != 1000000000 && d[next] > d[cur] + time)
            {
                d[next] = d[cur] + time;
                if (i == n - 1)
                    return (1);
            }
        }
    }
    return (0);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m >> w;
        int d[501] = { 0, };
        //for (int j = 1; j <= n; j++)
        //    d[j] = 1000000000;
        vector<pair<int, pair<int, int>>> arr;
        for (int j = 0; j < m; j++)
        {
            int start, end, time;
            cin >> start >> end >> time;
            arr.push_back({time, {start, end}});
            arr.push_back({time, {end, start}});
        }
        for (int j = 0; j < w; j++)
        {
            int start, end, time;
            cin >> start >> end >> time;
            arr.push_back({-time, {start , end}});
        }
        if (bf(arr, d) == 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return (0);
}