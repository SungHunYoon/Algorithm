#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p, w, c, v;
vector<pair<int, pair<int, int>>> arr;
int parent[1001];

int find(int index)
{
    if (parent[index] == index)
        return (index);
    parent[index] = find(parent[index]);
    return (parent[index]);
}

int makeUnion(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return (0);
    if (a > b)
        parent[a] = b;
    else
        parent[b] = a;
    return (1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> p >> w >> c >> v;
    for (int i = 0; i < w; i++)
    {
        int s, e, width;
        cin >> s >> e >> width;
        arr.push_back({width, {s, e}});
    }
    sort(arr.begin(), arr.end(), greater<>());
    for (int i = 0; i < p; i++)
        parent[i] = i;
    int answer = 1000000000;
    for (int i = 0; i < arr.size(); i++)
    {
        if (find(c) == find(v))
            break;
        if (makeUnion(arr[i].second.first, arr[i].second.second))
            answer = min(answer, arr[i].first);
    }
    cout << answer << '\n';
    return (0);
}