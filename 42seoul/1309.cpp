#include <iostream>

using namespace std;

int N;
long long dp[2][100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1
	// 3 : 1 1 1
	// 7 : 3 2 2
	// 17 : 7 5 5
	// 41 : 17 12 12

	cin >> N;
	dp[0][1] = 3;
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++)
	{
		dp[1][i] = (dp[0][i - 1] - dp[1][i - 1] + 9901) % 9901;
		dp[0][i] = (dp[0][i - 1] + (2 * dp[1][i])) % 9901;
	}
	cout << dp[0][N] << '\n';
	return 0;
}
