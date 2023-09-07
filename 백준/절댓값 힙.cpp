#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n;

struct cmp
{
    bool operator()(int a, int b) const
    {
        if (abs(a) != abs(b))
            return (abs(a) > abs(b));
        else
            return (a > b);
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    priority_queue<int, vector<int>, cmp> pq;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            if (!pq.empty())
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else
                cout << "0\n";
        }
        else
            pq.push(num);
    }
    return (0);
}