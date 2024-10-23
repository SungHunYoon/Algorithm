#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[300001];
int P[300001];
int dp[300001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		A[i] = A[i - 1] + i;
		P[i] = P[i - 1] + A[i];
	}
	fill(dp, dp + N + 1, 1e9);
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		if (P[i] > N)
			break;
		for (int j = P[i]; j <= N; j++)
			dp[j] = min(dp[j], dp[j - P[i]] + 1);
	}
	cout << dp[N] << '\n';
	return 0;
}