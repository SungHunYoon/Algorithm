#include <iostream>

using namespace std;

int N;
long dp[1001][3][2];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	dp[1][0][0] = dp[1][1][0] = dp[1][2][1] = 1;
	dp[2][0][0] = dp[2][1][0] = 2;
	dp[2][0][1] = dp[2][1][1] = 1;
	dp[2][2][1] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i][0][0] = dp[i][2][1] = (dp[i - 1][0][0] + dp[i - 1][1][0]) % 1000000;
		dp[i][0][1] = (dp[i - 1][0][1] + dp[i - 1][1][1] + dp[i - 1][2][1]) % 1000000;
		dp[i][1][0] = (dp[i - 1][1][0] + dp[i - 2][1][0] + dp[i - 3][1][0]) % 1000000;
		dp[i][1][1] = (dp[i][1][0] + dp[i - 1][1][1] + dp[i - 2][1][1] + dp[i - 3][1][1]) % 1000000;
	}
	cout << (dp[N][0][0] + dp[N][0][1] + dp[N][1][0] + dp[N][1][1] + dp[N][2][0] + dp[N][2][1]) % 1000000 << '\n';
	return 0;
}