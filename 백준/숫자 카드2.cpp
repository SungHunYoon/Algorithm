#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n;
    map<int, int> dict;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        map<int, int>::iterator iter;
        iter = dict.find(num);
        if (iter == dict.end())
            dict.insert({num, 1});
        else
            iter->second++;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        map<int, int>::iterator iter;
        iter = dict.find(num);
        if (iter == dict.end())
            cout << 0 << ' ';
        else
            cout << iter->second << ' ';
    }
    cout << '\n';
    return (0);
}