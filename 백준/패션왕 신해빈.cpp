#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int t;
int n;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int answer = 0;
        map<string, int> m;
        map<string, int>::iterator iter;
        for (int j = 0; j < n; j++)
        {
            string name, kind;
            cin >> name >> kind;
            iter = m.find(kind);
            if (iter != m.end())
                m[kind]++;
            else
                m.insert({kind, 1});
        }
        vector<int> cnt;
        for (iter = m.begin(); iter != m.end(); iter++)
            cnt.push_back(iter->second);
            
        for (int j = 0; j < cnt.size(); j++)
        {
            for (int k = j; k < cnt.size(); k++)
            {
                int tmp = cnt[k];
                for (int l = j; l < cnt.size() - k; l++)
                    tmp *= cnt[l];
                answer += tmp;
            }
        }
        cout << answer << '\n';
    }
    return (0);
}