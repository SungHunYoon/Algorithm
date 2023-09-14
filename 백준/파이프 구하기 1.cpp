#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int arr[16][16];
int dp[3][16][16];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    for (int i = 1; i < n; i++)
    {
        if (arr[0][i] == 0)
            dp[0][0][i] = 1;
        else
            break;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] == 0 && arr[i][j - 1] == 0 && arr[i - 1][j] == 0)
                dp[2][i][j] = dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
            if (arr[i][j] == 0 && arr[i][j - 1] == 0)
                dp[0][i][j] = dp[0][i][j - 1] + dp[2][i][j - 1];
            if (arr[i][j] == 0 && arr[i - 1][j] == 0)
                dp[1][i][j] = dp[1][i - 1][j] + dp[2][i - 1][j];
        }
    }
    cout << dp[0][n - 1][n - 1] + dp[1][n - 1][n - 1] + dp[2][n - 1][n - 1] << '\n';
    return (0);
}