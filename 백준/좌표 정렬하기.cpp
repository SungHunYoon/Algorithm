#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int cmp(pair<int, int> d1, pair<int, int> d2)
{
    if (d1.first != d2.first)
        return (d1.first < d2.first);
    else
        return (d1.second < d2.second);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < n; i++)
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    return (0);
}