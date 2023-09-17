#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int arr[501][501];
int dp[501][501];

int dfs(int x, int y, int val)
{
    if (x < 0 || y < 0 || x >= n || y >= n)
        return (0);
    else if (arr[y][x] <= val)
        return (0);
    else if (dp[y][x] != -1)
        return (dp[y][x]);
    dp[y][x] = max(dp[y][x], dfs(x + 1, y, arr[y][x]));
    dp[y][x] = max(dp[y][x], dfs(x - 1, y, arr[y][x]));
    dp[y][x] = max(dp[y][x], dfs(x, y + 1, arr[y][x]));
    dp[y][x] = max(dp[y][x], dfs(x, y - 1, arr[y][x]));
    dp[y][x]++;
    return (dp[y][x]);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
            cin >> arr[i][j];
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            answer = max(answer, dfs(j, i, 0));
    cout << answer << '\n';
    return (0);
}