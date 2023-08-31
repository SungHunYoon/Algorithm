#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    stack<char> s;
    int answer = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (!s.empty())
        {
            if (str[i] == ')')
            {
                if (str[i - 1] == '(')
                {
                    s.pop();
                    answer += s.size();
                }
                else
                {
                    s.pop();
                    answer++;
                }
                continue;
            }
        }
        s.push(str[i]);
    }
    cout << answer << '\n';
    return (0);
}