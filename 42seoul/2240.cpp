#include <iostream>
#include <vector>

using namespace std;

int T, W;
int arr[1001];
int dp[31][1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T >> W;
	for (int i = 0; i < T; i++)
		cin >> arr[i];
	for (int i = 0; i <= W; i++)
		dp[i][1] = arr[0] == i % 2 + 1 ? 1 : 0;
	for (int i = 2; i <= T; i++)
		dp[0][i] = arr[i - 1] == 1 ? dp[0][i - 1] + 1 : dp[0][i - 1];
	for (int i = 1; i <= W; i++)
	{
		for (int j = 2; j <= T; j++)
		{
			if (arr[j - 1] == 1)
			{
				if (i % 2 == 0)
					dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1);
				else
					dp[i][j] = dp[i][j - 1];
			}
			else
			{
				if (i % 2 == 1)
					dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1);
				else
					dp[i][j] = dp[i][j - 1];
			}

		}
	}

	// cout << "-----------------\n";
	// for (int i = 0; i <= W; i++)
	// {
	// 	for (int j = 1; j <= T; j++)
	// 		cout << dp[i][j] << ' ';
	// 	cout << '\n';
	// }

	int answer = 0;
	for (int i = 0; i <= W; i++)
		answer = max(answer, dp[i][T]);
	cout << answer << '\n';
	return 0;
}