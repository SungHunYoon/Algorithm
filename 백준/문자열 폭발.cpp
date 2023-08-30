#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <utility>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    string e;
    cin >> str >> e;

    stack<pair<char, int>> s;
    int eIndex;
    for (int i = 0; i < str.length(); i++)
    {
        if (s.empty())
            eIndex = 0;
        else
            eIndex = s.top().second;
        if (str[i] == e[eIndex])
            eIndex++;
        else
        {
            if (str[i] == e[0])
                eIndex = 1;
            else
                eIndex = 0;
        }

        s.push({str[i], eIndex});
        if (eIndex == e.length())
        {
            for (int j = 0; j < eIndex; j++)
                s.pop();
        }
    }
    int index = s.size();
    if (index == 0)
        cout << "FRULA\n";
    else
    {
        char answer[index + 1];
        answer[index] = 0;
        while (!s.empty())
        {
            answer[index - 1] = s.top().first;
            s.pop();
            index--;
        }
        cout << answer << '\n';
    }  
    return (0);
}