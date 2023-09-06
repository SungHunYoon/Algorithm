#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int bfs(int n, int k)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    int max = n > k ? n : k;
    bool v[max + 1] = { false, };
    v[n] = true;
    q.push({cnt, n});
    while (!q.empty())
    {
        cnt = q.front().first;
        int x = q.front().second;
        q.pop();
        if (x == k)
            break;
        if (x * 2 < max + 1 && !v[x * 2])
        {
            v[x * 2] = true;
            q.push({cnt + 1, x * 2});
        }
        if (x + 1 < max + 1 && !v[x + 1])
        {
            v[x + 1] = true;
            q.push({cnt + 1, x + 1});
        }
        if (x - 1 >= 0 && !v[x - 1])
        {
            v[x - 1] = true;
            q.push({cnt + 1, x - 1});
        }
    }
    return (cnt);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    cout << bfs(n, k) << '\n';
    return (0);
}