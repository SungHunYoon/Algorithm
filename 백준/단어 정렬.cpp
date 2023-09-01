#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

struct cmp
{
    bool operator() (const string &s1, const string &s2)
    {
        if (s1.size() == s2.size())
            return s1 < s2;
        else
            return s1.size() < s2.size();
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    set<string, cmp> arr;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr.insert(s);
    }
    for (set<string, cmp>::iterator iter = arr.begin(); iter != arr.end(); iter++)
        cout << *iter << '\n';
    return (0);
}