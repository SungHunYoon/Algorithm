#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
string s;

vector<int> getPi(string p)
{
    int m = (int)p.length(), j = 0;
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return (pi);
}

vector<int> kmp(string str, string p)
{
    vector<int> ans;
    vector<int> pi = getPi(p);
    int n = (int)str.length(), m = (int)p.length(), j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && s[i] != p[j])
            j = pi[j - 1];
        if (s[i] == p[j])
        {
            if (j == m - 1)
            {
                ans.push_back(i - m + 1);
                j = pi[j];
            }
            else
                j++;
        }
    }
    return (ans);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> s;
    string p = "";
    int len = 2 * n + 1;
    for (int i = 0; i < len; i++)
    {
        if (i % 2 == 0)
            p.push_back('I');
        else
            p.push_back('O');
    }
    vector<int> answer = kmp(s, p);
    cout << answer.size() << '\n';
    return (0);
}