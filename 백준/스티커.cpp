#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int n;
int arr[100001][2];
int dp[100001][2];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < n; k++)
                cin >> arr[k][j];
        
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                dp[j][0] = arr[j][0];
                dp[j][1] = arr[j][1];
            }
            else
            {
                dp[j][0] = max(dp[j - 2][1], dp[j - 1][1]) + arr[j][0];
                dp[j][1] = max(dp[j - 2][0], dp[j - 1][0]) + arr[j][1];
            }
        }
        cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
    }
    return (0);
}