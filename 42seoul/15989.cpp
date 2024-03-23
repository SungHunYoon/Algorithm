#include <iostream>

using namespace std;

int T, N;
int dp[3][10001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	dp[0][1] = 1;
	dp[1][1] = 0;
	dp[2][1] = 0;

	dp[0][2] = 1;
	dp[1][2] = 1;
	dp[2][2] = 0;

	dp[0][3] = 1;
	dp[1][3] = 1;
	dp[2][3] = 1;
	
	for (int i = 4; i <= 10000; i++)
	{
		dp[0][i] = 1;
		dp[1][i] = dp[1][i - 2] + 1;
		dp[2][i] = dp[0][i - 3] + dp[1][i - 3] + dp[2][i - 3];
	}
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << dp[0][N] + dp[1][N] + dp[2][N] << '\n';
	}
	return 0;
}