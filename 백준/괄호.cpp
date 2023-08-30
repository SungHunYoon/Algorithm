#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string str;
        cin >> str;

        int cnt = 0;
        int j;
        for (j = 0; j < str.length(); j++)
        {
            if (str[j] == '(')
                cnt++;
            else
            {
                if (cnt > 0)
                    cnt--;
                else
                    break;
            }
        }
        if (j == str.length() && cnt == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return (0);
}