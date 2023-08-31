#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<char> org;
    char c;
    while (cin.get(c), c != '\n')
        org.push(c);

    int m;
    cin >> m;
    stack<char> ref;
    for (int i = 0; i < m; i++)
    {
        char a;
        cin >> a;

        if (a == 'L')
        {
            if (!org.empty())
            {
                ref.push(org.top());
                org.pop();
            }
        }
        else if (a == 'D')
        {
            if (!ref.empty())
            {
                org.push(ref.top());
                ref.pop();
            }
        }
        else if (a == 'B')
        {
            if (!org.empty())
                org.pop();
        }
        else
        {
            cin >> a;
            org.push(a);
        }
    }
    char answer[org.size() + ref.size() + 1];
    answer[org.size() + ref.size()] = 0;
    int index = org.size();
    while (!ref.empty())
    {
        answer[index++] = ref.top();
        ref.pop();
    }
    index = org.size() - 1;
    while (!org.empty())
    {
        answer[index--] = org.top();
        org.pop();
    }
    cout << answer << '\n';
    return (0);
}