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

    while (1)
    {
        char str[101];
        cin.getline(str, 101);
        if (str[0] == '.')
            break;
        stack<char> stk;
        int i;
        for (i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == '(' || str[i] == '[')
                stk.push(str[i]);
            else if (str[i] == ')')
            {
                if (!stk.empty() && stk.top() == '(')
                    stk.pop();
                else
                    break;
            }
            else if (str[i] == ']')
            {
                if (!stk.empty() && stk.top() == '[')
                    stk.pop();
                else
                    break;
            }
        }
        if (str[i] != '\0')
            cout << "no\n";
        else
            cout << "yes\n";
    }

    return (0);
}