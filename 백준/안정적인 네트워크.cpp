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
        int x, y;
        cin >> x >> y;
        arr.push_back({0, {x, y}});
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cost;
            cin >> cost;
            if (i != 1 && j != 1 && i != j)
                arr.push_back({cost, {i, j}});
        }
    }
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    sort(arr.begin(), arr.end());
    int cnt = 0;
    int cost = 0;
    vector<pair<int, int>> answer;
    for (int i = 0; i < arr.size(); i++)
    {
        if (find(arr[i].second.first) != find(arr[i].second.second))
        {
            makeUnion(arr[i].second.first , arr[i].second.second);
            cost += arr[i].first;
            if (arr[i].first != 0)
                answer.push_back({arr[i].second.first, arr[i].second.second});
            cnt++;
            if (cnt == n - 2)
                break;
        }
    }
    cout << cost << ' ' << answer.size() << '\n';
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i].first << ' ' << answer[i].second << '\n';
    return (0);
}