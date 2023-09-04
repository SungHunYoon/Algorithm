#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int cmp(string s1, string s2)
{
    return (s1 > s2);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    map<string, int> dict;
    for (int i = 0; i < n; i++)
    {
        string name, enterance;
        cin >> name >> enterance;

        map<string, int>::iterator iter;
        iter = dict.find(name);
        if (iter != dict.end())
        {
            if (enterance == "enter")
                iter->second = 1;
            else
                iter->second = 0;
        }
        else
        {
            if (enterance == "enter")
                dict.insert({name, 1});
            else
                dict.insert({name, 0});
        }
    }
    vector<string> answer;
    for (map<string, int>::iterator iter = dict.begin(); iter != dict.end(); iter++)
    {
        if (iter->second == 1)
            answer.push_back(iter->first);
    }
    sort(answer.begin(), answer.end(), cmp);
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << '\n';
    return (0);
}