#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int m;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m;
    set<int> s;
    for (int i = 0; i < m; i++)
    {
        string str;
        int num;
        cin >> str;
        if (str == "add")
        {
            cin >> num;
            s.insert(num);
        }
        else if (str == "check")
        {
            cin >> num;
            if (s.find(num) != s.end())
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (str == "remove")
        {
            cin >> num;
            set<int>::iterator iter = s.find(num);
            if (iter != s.end())
                s.erase(iter);
        }
        else if (str == "toggle")
        {
            cin >> num;
            set<int>::iterator iter = s.find(num);
            if (iter != s.end())
                s.erase(iter);
            else
                s.insert(num);
        }
        else if (str == "all")
        {
            for (int j = 1; j <= 20; j++)
                s.insert(j);
        }
        else
            s.erase(s.begin(), s.end());
        
    }
    return (0);
}