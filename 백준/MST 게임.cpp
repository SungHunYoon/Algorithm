#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
vector<pair<int, pair<int, int>>> arr;
int parent[1001];
int answer[1001];

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

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        arr.push_back({i + 1, {s, e}});
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 1; j <= n; j++)
            parent[j] = j;
        int cnt = 0;
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            if (find(arr[j].second.first) != find(arr[j].second.second))
            {
                makeUnion(arr[j].second.first, arr[j].second.second);
                sum += arr[j].first;
                cnt++;
                if (cnt == n - 1)
                {
                    answer[i] = sum;
                    break;
                }
            }
        }
        cout << answer[i] << ' ';
    }
    cout << '\n';
    return (0);
}