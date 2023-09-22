#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int t, n, k, w;
int arr[1001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        for (int j = 1; j <= n; j++)
            cin >> arr[j];
        vector<int> v[1001];
        int inDegree[1001];
        for (int j = 0; j < k; j++)
        {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            inDegree[y]++;
        }
        cin >> w;
        queue<int> q;
        long long answer[1001] = { 0, };
        for (int j = 1; j <= n; j++)
        {
            if (inDegree[j] == 0)
            {
                answer[j] = arr[j];
                q.push(j);
            }
        }
        int result[1001];
        for (int j = 1; j <= n; j++)
        {
            if (q.empty())
                break;
            int x = q.front();
            q.pop();
            result[j] = x;
            for (int l = 0; l < v[x].size(); l++)
            {
                int y = v[x][l];
                answer[y] = max(answer[y], answer[x] + arr[y]);
                if (--inDegree[y] == 0)
                    q.push(y);
            }
        }
        cout << answer[w] << '\n';
    }
    return (0);
}A