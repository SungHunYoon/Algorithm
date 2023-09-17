#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int dp[101][100001];
int item[101][2];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> item[i][0] >> item[i][1];
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (item[i][0] <= j)
                dp[i][j] = max(item[i][1] + dp[i - 1][j - item[i][0]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][k] << '\n';
    return (0);
}