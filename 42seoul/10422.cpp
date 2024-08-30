#include <iostream>

using namespace std;
using ll = long long;

int T, L;
ll dp[5001];
ll M = 1e9 + 7;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	dp[0] = 1;
	for (int i = 2; i < 5001; i += 2) {
		for (int j = 2; j <= i; j += 2) {
			dp[i] = (dp[i] + (dp[j - 2] * dp[i - j])) % M;
		}
	}
	while (T--) {
		cin >> L;
		cout << dp[L] << '\n';
	}
	return 0;
}