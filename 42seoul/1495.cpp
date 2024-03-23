#include <iostream>

using namespace std;

int N, S, M;
int arr[51];
int dp[51][1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	dp[0][S] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (dp[i - 1][j] == 1)
			{
				if (j - arr[i] >= 0)
					dp[i][j - arr[i]] = 1;
				if (j + arr[i] <= M)
					dp[i][j + arr[i]] = 1;
			}
		}
	}
	// for (int i = 1; i <= N; i++)
	// {
	// 	for (int j = 0; j <= M; j++)
	// 		cout << dp[i][j] << ' ';
	// 	cout << '\n';
	// }
	int answer = -1;
	for (int i = 0; i <= M; i++)
	{
		if (dp[N][i] == 1)
			answer = max(answer, i);
	}
	cout << answer << '\n';
	return 0;
}


// 5 -> 2 or 8
// 3 -> -1 or 5 or 5 or 11