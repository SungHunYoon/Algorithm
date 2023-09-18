#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

string str;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> str;
    stack<char> s;
    int i;
    for (i = 0; i < str.length(); i++)
    {
        if (!s.empty())
        {
            if (str[i] == 'P')
            {
                if (s.top() == 'A')
                {
                    for (int j = 0; j < 3; j++)
                        s.pop();
                }
                s.push(str[i]);
            }
            else
            {
                if (s.size() < 2)
                    break;
                else if (s.top() == 'A')
                    break;
                s.push(str[i]);
            }
        }
        else
        {
            if (str[i] == 'A')
                break;
            s.push(str[i]);
        }
    }
    if (i == str.length() && s.size() == 1 && s.top() == 'P')
        cout << "PPAP\n";
    else
        cout << "NP\n";
    return (0);
}