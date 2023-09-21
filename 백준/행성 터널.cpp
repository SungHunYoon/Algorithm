#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct s_planet
{
    int x, y, z;
    int num;
} t_planet;

int n;
int parent[100001];
vector<t_planet> arr;
vector<pair<int, pair<int, int>>> e;

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

int getCost(t_planet a, t_planet b)
{
    return (min(abs(a.x - b.x), min(abs(a.y - b.y), abs(a.z - b.z))));
}

int cmpX(t_planet a, t_planet b)
{
    return (a.x < b.x);
}

int cmpY(t_planet a, t_planet b)
{
    return (a.y < b.y);
}

int cmpZ(t_planet a, t_planet b)
{
    return (a.z < b.z);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        arr.push_back({x, y, z, i});
    }

    sort(arr.begin(), arr.end(), cmpX);
    for (int i = 0; i < n - 1; i++)
        e.push_back({getCost(arr[i], arr[i + 1]), {arr[i].num, arr[i + 1].num}});

    sort(arr.begin(), arr.end(), cmpY);
    for (int i = 0; i < n - 1; i++)
        e.push_back({getCost(arr[i], arr[i + 1]), {arr[i].num, arr[i + 1].num}});
    
    sort(arr.begin(), arr.end(), cmpZ);
    for (int i = 0; i < n - 1; i++)
        e.push_back({getCost(arr[i], arr[i + 1]), {arr[i].num, arr[i + 1].num}});

    sort(e.begin(), e.end());

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    long long answer = 0;
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