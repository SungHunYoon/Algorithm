#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[125251];
int dp[125251];

int recursive(int stair, int index)
{
    if (stair >= n - 1)
        return (arr[index]);
    if (dp[index] != 0)
        return (dp[index]);
    int left = recursive(stair + 1, index + stair + 1);
    int right = recursive(stair + 1, index + stair + 2);
    dp[index] = arr[index] + max(left, right);
    return (dp[index]);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    int idx = 1;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            cin >> arr[idx++];
    
    cout << recursive(0, 1) << '\n';
    return (0);
}