#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

int cmp(pair<int, pair<int, string>> d1, pair<int, pair<int, string>> d2)
{
    if (d1.second.first != d2.second.first)
        return (d1.second.first < d2.second.first);
    else
        return (d1.first < d2.first);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, pair<int, string>>> arr;
    for (int i = 0; i < n; i++)
    {
        int old;
        string name;
        cin >> old >> name;
        arr.push_back({i, {old, name}});
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < n; i++)
        cout << arr[i].second.first << ' ' << arr[i].second.second << '\n';
    return (0);
}