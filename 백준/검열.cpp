#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string w, str;
    cin >> w >> str;
    int left = 0;
    int right = str.length() - 1;
    int dir = 0;
    deque<char> l;
    deque<char> r;
    while (left <= right)
    {
        if (dir == 0)
        {
            while (left <= right)
            {
                l.push_back(str[left++]);
                if (l.size() >= w.length())
                {
                    int i;
                    for (i = 0; i < w.length(); i++)
                    {
                        if (l[l.size() - w.length() + i] != w[i])
                            break;
                    }
                    if (i == w.length())
                    {
                        for (i = 0; i < w.length(); i++)
                            l.pop_back();
                        dir = 1;
                        break;
                    }
                }
            }
        }
        else
        {
            while (left <= right)
            {
                r.push_front(str[right--]);
                if (r.size() >= w.length())
                {
                    int i;
                    for (i = 0; i < w.length(); i++)
                    {
                        if (r[i] != w[i])
                            break;
                    }
                    if (i == w.length())
                    {
                        for (i = 0; i < w.length(); i++)
                            r.pop_front();
                        dir = 0;
                        break;
                    }
                }
            }
        }
    }
    string answer = "";
    while (!l.empty())
    {
        answer.push_back(l.front());
        l.pop_front();
    }
    while (!r.empty())
    {
        answer.push_back(r.front());
        r.pop_front();
    }
    
    int index;
    while ((index = answer.find(w)) != string::npos)
        answer.erase(answer.begin() + index, answer.begin() + index + w.length());

    cout << answer << '\n';
    return (0);
}