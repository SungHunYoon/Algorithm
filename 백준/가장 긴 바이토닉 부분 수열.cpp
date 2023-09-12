#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[1001];
int dp[1001];
int dp1[1001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];


    for (int i = 1; i <= n; i++)
    {
        int here = 0;
        for (int j = 1; j < i; j++)
        {
            if (arr[j] < arr[i])
                here = max(here, dp[j]);
        }
        dp[i] = here + 1;
    }

    for (int i = n; i > 0; i--)
    {
        int here = 0;
        for (int j = n; j > i; j--)
        {
            if (arr[j] < arr[i])
                here = max(here, dp1[j]);
        }
        dp1[i] = here + 1;
    }

    int answer = 0;
    for (int i = 0; i <= n; i++)
    {
        if (dp[i] + dp1[i] - 1 > answer)
            answer = dp[i] + dp1[i] - 1;
    }
    cout << answer << '\n';

    return (0);
}