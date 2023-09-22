#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int result[32001];
vector<int> v[32001];
int inDegree[32001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        inDegree[y]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (q.empty())
            break;
        int x = q.front();
        q.pop();
        result[i] = x;
        for (int j = 0; j < v[x].size(); j++)
        {
            int y = v[x][j];
            if (--inDegree[y] == 0)
                q.push(y);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << result[i] << ' ';
    cout << '\n';
    return (0);
}