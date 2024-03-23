#include <iostream>
#include <algorithm>

using namespace std;

int N, T, K, S;
pair<int, int> arr[101];
int dp[101][10001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> T;
	for (int i = 1; i <= N; i++)
		cin >> arr[i].first >> arr[i].second;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= T; j++)
		{
			if (j >= arr[i].first)
				dp[i][j] = max(arr[i].second + dp[i - 1][j - arr[i].first], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
			//cout << dp[i][j] << ' ';
		}
		//cout << '\n';
	}
	cout << dp[N][T] << '\n';
	return 0;
}

