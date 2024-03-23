#include <iostream>

using namespace std;

int N, K;
long long dp[1002][1002];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	dp[0][1] = 1;

	for (int i = 1; i <= N + 1; i++)
		for (int j = 1; j <= i; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
	cout << dp[N + 1][K + 1] << '\n';
	return 0;
}