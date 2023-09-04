#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    
    queue<int> q;
    for (int i = 0; i < n; i++)
        q.push(i + 1);

    int i = 1;
    cout << '<';
    while (!q.empty())
    {
        if (i == k)
        {
            cout << q.front();
            q.pop();
            if (!q.empty())
                cout << ", ";
            i = 1;
        }
        else
        {
            q.push(q.front());
            q.pop();
            i++;
        }
    }
    cout << '>';
    return (0);
}