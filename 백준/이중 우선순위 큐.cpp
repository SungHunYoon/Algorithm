#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int t;
int k;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> k;
        multiset<int> ms;
        for (int j = 0; j < k; j++)
        {
            char c;
            int num;
            cin >> c >> num;
            if (c == 'I')
                ms.insert(num);
            else
            {
                if (ms.size() > 0)
                {
                    if (num == -1)
                        ms.erase(ms.begin());
                    else
                    {
                        multiset<int>::iterator iter = ms.end();
                        iter--;
                        ms.erase(iter);
                    }
                }
            }
        }
        if (ms.size() == 0)
            cout << "EMPTY\n";
        else
        {
            multiset<int>::iterator iter = ms.end();
            iter--;
            cout << *iter << ' ' << *ms.begin() << '\n';
        }
    }
    return (0);
}