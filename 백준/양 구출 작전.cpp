#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int dfs(vector<pair<char, int>> &arr, vector<vector<int>> &v, int index)
{
    int ret = 0;
    for (int i = 0; i < v[index].size(); i++)
        ret += dfs(arr, v, v[index][i]);

    if (arr[index].first == 'S')
        ret += arr[index].second;
    else
        ret -= arr[index].second;
    if (ret < 0)
        ret = 0;
    return (ret);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    vector<pair<char, int>> arr (n + 1);
    arr[1].first = 'S';
    arr[1].second = 0;
    for (int i = 2; i <= n; i++)
    {
        char a;
        int u, s;
        cin >> a >> u >> s;
        arr[i].first = a;
        arr[i].second = u;
        v[s].push_back(i);
    }
    cout << dfs(arr, v, 1) << '\n';
    return (0);
}