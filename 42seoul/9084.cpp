#include <iostream>
#include <algorithm>

using namespace std;

int T, N, M;
int arr[21];
int dp[10001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		for (int j = 1; j <= N; j++)
			cin >> arr[j];
		cin >> M;
		fill(dp, dp + M + 1, 0);
		dp[0] = 1;
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= M; k++)
				if (k - arr[j] >= 0)
					dp[k] += dp[k - arr[j]];
		// for (int j = 1; j <= M; j++)
		// 	cout << dp[j] << ' ';
		// cout << '\n';
		cout << dp[M] << '\n';
	}

	return 0;
}