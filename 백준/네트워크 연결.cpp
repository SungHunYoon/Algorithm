#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int parent[1001];
vector<pair<int, pair<int, int>>> arr;

int find(int index)
{
    if (parent[index] == index)
        return (index);
    parent[index] = find(parent[index]);
    return (parent[index]);
}

void makeUnion(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return;
    if (a > b)
        parent[a] = b;
    else
        parent[b] = a;
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
        parent[i] = i;

    sort(arr.begin(), arr.end());
    int answer = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        if (find(arr[i].second.first) != find(arr[i].second.second))
        {
            makeUnion(arr[i].second.first, arr[i].second.second);
            answer += arr[i].first;
            cnt++;
            if (cnt == n - 1)
                break;
        }
    }
    cout << answer << '\n';
    return (0);
}