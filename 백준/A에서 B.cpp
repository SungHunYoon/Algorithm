#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int a, b;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;
    queue<int> q;
    q.push(a);
    int answer = 1000000000;
    int cnt = 0;
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            int x = q.front();
            q.pop();
            if (x == b)
            {
                if (answer > cnt)
                    answer = cnt;
            }
            long long tmp;
            tmp = (long long)x * 2;
            if (tmp <= b)
                q.push(tmp);
            tmp = (long long)x * 10 + 1;
            if (tmp <= b)
                q.push(tmp);
        }
        cnt++;
    }
    if (answer == 1000000000)
        cout << "-1\n";
    else
        cout << answer + 1 << '\n';
    return (0);
}