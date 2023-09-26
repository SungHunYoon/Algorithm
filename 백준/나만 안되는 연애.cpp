#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int parent[1001];
int info[1001];
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
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == 'W')
            info[i] = 1;
        parent[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        arr.push_back({d, {u, v}});
    }
    sort(arr.begin(), arr.end());
    
    int cnt = 0;
    int answer = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int a, b;
        a = arr[i].second.first;
        b = arr[i].second.second;
        if (find(a) != find(b) && info[a] != info[b])
        {
            makeUnion(a, b);
            answer += arr[i].first;
            cnt++;
            if (cnt == n - 1)
                break;
        }
    }
    if (cnt == n - 1)
        cout << answer << '\n';
    else
        cout << "-1\n";
    return (0);
}