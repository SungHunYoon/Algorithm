#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long dp[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	dp[1] = 1; dp[2] = 2; dp[3] = 3;
	for (int i = 4; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; j <= i - 4; j++) {
			dp[i] = max(dp[i], dp[j] + (((i - (j + 2)) * dp[j])));
		}
	}
	cout << dp[N] << '\n';
	return 0;
}