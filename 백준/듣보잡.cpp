#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<string, int> dict;
    for (int i = 0; i < n + m; i++)
    {
        string name;
        cin >> name;

        map<string, int>::iterator iter;
        iter = dict.find(name);
        if (iter != dict.end())
            iter->second++;
        else
            dict.insert({name, 1});
    }
    int cnt = 0;
    vector<string> answer;
    for (map<string, int>::iterator iter = dict.begin(); iter != dict.end(); iter++)
    {
        if (iter->second > 1)
        {
            cnt++;
            answer.push_back(iter->first);
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << '\n';
    return (0);
}