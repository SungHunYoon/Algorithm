#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> arr;
int d[501];

int bf(int idx)
{
    d[idx] = 0;
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
  
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        arr.push_back({t, {s, e}});
    }
    for (int i = 1; i <= n; i++)
        d[i] = 1000000000;
    if (bf(1) == 1)
        cout << "-1\n";
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (d[i] != 1000000000)
                cout << d[i] << '\n';
            else
                cout << "-1\n";
        }
    }

    return (0);
}