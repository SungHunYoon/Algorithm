#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    stack<char> s;
    int flag = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
            cout << str[i];
        else
        {
            if (str[i] == ')')
            {
                while (s.top() != '(')
                {
                    cout << s.top();
                    s.pop();
                }
                s.pop();
            }
            else
            {
                if (s.empty() || str[i] == '(' || s.top() == '(')
                    s.push(str[i]);
                else
                {
                    if ((str[i] == '*' || str[i] == '/') && (s.top() == '+' || s.top() == '-'))
                    {
                        s.push(str[i]);
                    }
                    else if ((str[i] == '*' || str[i] == '/') && (s.top() == '*' || s.top() == '/'))
                    {
                        cout << s.top();
                        s.pop();
                        s.push(str[i]);
                    }
                    else
                    {
                        while (!s.empty() && s.top() != '(')
                        {
                            cout << s.top();
                            s.pop();
                        }
                        s.push(str[i]);
                    }
                }
            }
        }
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << '\n';
    return (0);
}