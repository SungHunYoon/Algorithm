#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[41];
int dp[2][41];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= M; i++)
		cin >> arr[i];
	for (int i = 1; i <= M; i++)
		dp[0][arr[i]] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++)
	{
		if (dp[0][i] == 0 && dp[0][i - 1] == 0)
			dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
		else
			dp[1][i] = dp[1][i - 1];
	}
	cout << dp[1][N] << '\n';
	return 0;
}

// 1 2 3 4 5 6 7 8 9

// 0 0 0 1 0 0 1 0 0
// 1 2 3 3 3 6 6 6 12