#include <iostream>
#include <algorithm>

using namespace std;

int T, N;
long long dp[1000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		fill(dp, dp + 1000001, 0);
		cin >> N;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int j = 4; j <= N; j++)
			dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]) % 1000000009;
		cout << dp[N] << '\n';
	}

	return 0;
}