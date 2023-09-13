#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int n, k;
int visit[100050];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < 100050; i++)
        visit[i] = 1000000000;
    deque<pair<int, int>> q;
    visit[n] = 0;
    q.push_back({0, n});
    while (!q.empty())
    {
        int x = q.front().second;
        int cnt = q.front().first;
        q.pop_front();
        if (x == k)
        {
            cout << cnt << '\n';
            break;
        }
        if (x * 2 < 100050 && visit[x * 2] > cnt)
        {
            visit[x * 2] = cnt;
            q.push_front({cnt, x * 2});
        }
        if (x + 1 < 100050 && visit[x + 1] > cnt)
        {
            visit[x + 1] = cnt + 1;
            q.push_back({cnt + 1, x + 1});
        }
        if (x - 1 >= 0 && visit[x - 1] > cnt)
        {
            visit[x - 1] = cnt + 1;
            q.push_back({cnt + 1, x - 1});
        }
    }
    return (0);
}