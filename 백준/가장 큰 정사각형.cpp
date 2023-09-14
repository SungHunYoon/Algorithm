#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[1001][1001];
int dp[1001][1001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
            dp[i][j] = c - '0';
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] != 0)
                dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
            if (dp[i][j] > answer)
                answer = dp[i][j];
        }
    }
    cout << answer * answer << '\n';
    return (0);
}