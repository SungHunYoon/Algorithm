#include <iostream>

using namespace std;

int N;
int arr[101];
long long dp[101][21];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	dp[1][arr[1]] = 1;
	for (int i = 2; i <= N - 1; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (dp[i - 1][j] > 0)
			{
				if (0 <= j - arr[i])
					dp[i][j - arr[i]] += dp[i - 1][j];
				if (20 >= j + arr[i])
					dp[i][j + arr[i]] += dp[i - 1][j];
			}
		}
	}
	// for (int i = 1; i <= N; i++)
	// {
	// 	for (int j = 1; j <= 20; j++)
	// 		cout << dp[i][j] << ' ';
	// 	cout << '\n';
	// }
	cout << dp[N - 1][arr[N]] << '\n';
	return 0;
}