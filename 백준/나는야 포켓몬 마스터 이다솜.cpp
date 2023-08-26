#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <string>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;
    map<string, int> dict;
    vector<string> findlist;

    cin >> n;
    cin >> m;
    findlist.assign(n, "");
    for (int i = 0; i < n; i++)
    {
        string tmp1;
        cin >> tmp1;
        dict.insert(make_pair(tmp1, i + 1));
        findlist[i] = tmp1;
    }
    for (int i = 0; i < m; i++)
    {
        string t;
        cin >> t;
        if (t[0] >= '0' && t[0] <= '9')
            cout << findlist[stoi(t) - 1] << '\n';
        else
            cout << dict[t] << '\n';
    }
    return (0);
}