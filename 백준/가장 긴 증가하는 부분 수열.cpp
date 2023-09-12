#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[1001];
int dp[1001];

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
    cout << *max_element(dp + 1, dp + n + 1) << '\n';

/*
    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        int *pos = lower_bound(dp + 1, dp + len + 1, arr[i]);
        *pos = arr[i];
        if (pos == dp + len + 1)
            len++;
    }
    cout << len << '\n';
*/
    return (0);
}