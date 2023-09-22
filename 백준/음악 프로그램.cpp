#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int result[1001];
vector<int> v[1001];
int inDegree[1001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;
        int prev = 0;
        for (int j = 0; j < c; j++)
        {
            int num;
            cin >> num;
            if (j != 0)
            {
                v[prev].push_back(num);
                inDegree[num]++;
            }
            prev = num;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (q.empty())
        {
            flag = 1;
            break;
        }
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
    if (flag == 1)
        cout << "0\n";
    else
    {
        for (int i = 1; i <= n; i++)
            cout << result[i] << ' ';
        cout << '\n';
    }
    return (0);
}