#include <iostream>
#include <cmath>

using namespace std;

int N;
int dp[31];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	dp[2] = 3;
	dp[4] = 11;
	for (int i = 6; i <= N; i += 2)
		dp[i] = dp[i - 2] * 3 + dp[i - 2] - dp[i - 4];
	cout << dp[N] << '\n';
	return 0;
}

// 2 * N 타일링
// 1 2 3 5 8 13 21 34
// 3 * N 타일링
// 4 : 3 * 3 + 2 = 11
// 6 : 3 * 3 * 3 + 2 * 3 + 2 * 3 + 2 = 41
