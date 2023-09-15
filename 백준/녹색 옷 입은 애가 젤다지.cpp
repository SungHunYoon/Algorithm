#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int arr[126][126];
int dp[126][126];

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 0;
    while (cin >> n)
    {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
                dp[i][j] = -1;
            }
        }
        queue<pair<int, int>> q;
        dp[0][0] = arr[0][0];
        q.push({0, 0});
        while (!q.empty())
        {
            pair<int, int> x = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int dx, dy;
                dx = x.first + nx[i];
                dy = x.second + ny[i];
                if (0 <= dx && dx < n && 0 <= dy && dy < n)
                {
                    if (dp[dy][dx] == -1 || dp[dy][dx] > dp[x.second][x.first] + arr[dy][dx])
                    {
                        dp[dy][dx] = dp[x.second][x.first] + arr[dy][dx];
                        q.push({dx, dy});
                    }
                }
            }
        }
        cout << "Problem " << t + 1 << ": " << dp[n - 1][n - 1] << '\n';
        t++;
    }
    return (0);
}