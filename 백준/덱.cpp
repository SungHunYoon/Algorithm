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

    int n;
    cin >> n;

    deque<int> dq;

    for (int i = 0; i < n; i++)
    {
        string cmd;
        int num;
        cin >> cmd;

        if (cmd == "push_front")
        {
            cin >> num;
            dq.push_front(num);
        }
        else if (cmd == "push_back")
        {
            cin >> num;
            dq.push_back(num);
        }
        else if (cmd == "pop_front")
        {
            if (!dq.empty())
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            else
                cout << "-1\n";
        }
        else if (cmd == "pop_back")
        {
            if (!dq.empty())
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else
                cout << "-1\n";
        }
        else if (cmd == "size")
            cout << dq.size() << '\n';
        else if (cmd == "empty")
            cout << (int)dq.empty() << '\n';
        else if (cmd == "front")
        {
            if (!dq.empty())
                cout << dq.front() << '\n';
            else
                cout << "-1\n";
        }
        else if (cmd == "back")
        {
            if (!dq.empty())
                cout << dq.back() << '\n';
            else
                cout << "-1\n";
        }
    }
    return (0);
}