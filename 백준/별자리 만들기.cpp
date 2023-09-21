#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int parent[101];
pair<double, double> arr[101];
vector<pair<double, pair<int, int>>> e;

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

double distance(pair<double, double> a, pair<double, double> b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            e.push_back({distance(arr[i], arr[j]), {i, j}});
    sort(e.begin(), e.end());

    double answer = 0;
    int cnt = 0;
    for (int i = 0; i < e.size(); i++)
    {
        if (find(e[i].second.first) != find(e[i].second.second))
        {
            makeUnion(e[i].second.first, e[i].second.second);
            answer += e[i].first;
            cnt++;
            if (cnt == n - 1)
                break;
        }
    }
    cout << answer << '\n';
    return (0);
}