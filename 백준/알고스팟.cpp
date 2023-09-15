#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int arr[101][101];
int dp[101][101];

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
            dp[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    dp[0][0] = 0;
    q.push({0, 0});
    int answer = 1000000000;
    while (!q.empty())
    {
        pair<int, int> x = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int dx, dy;
            dx = x.first + nx[i];
            dy = x.second + ny[i];
            if (0 <= dx && dx < m && 0 <= dy && dy < n)
            {
                if (dp[dy][dx] == -1 || dp[dy][dx] > dp[x.second][x.first] + arr[x.second][x.first])
                {
                    dp[dy][dx] = dp[x.second][x.first] + arr[x.second][x.first];
                    q.push({dx, dy});
                }
            }
        }
    }
    cout << dp[n - 1][m - 1] << '\n';
    return (0);
}