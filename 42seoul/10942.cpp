#include <iostream>

using namespace std;

int N, M, S, E;
int arr[2001];
long long dp[2001][2001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				dp[i][j] = 1;
			else if (arr[i] == arr[j] && (dp[i][j - 1] == 1 || dp[i - 1][j + 1] == 1))
				dp[i][j] = 1;
		}
	}
	// for (int i = 0; i < N; i++)
	// {
	// 	for (int j = 0; j < N; j++)
	// 		cout << dp[i][j] << ' ';
	// 	cout << '\n';
	// }
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> S >> E;
		cout << dp[E - 1][S - 1] << '\n';
	}
	return 0;
}

// 1 2 1 3 1 2 1
// 1 0 0 0 0 0 0 
// 0 1 0 0 0 0 0 
// 1 0 1 0 0 0 0 
// 0 0 0 1 0 0 0 
// 0 0 1 0 1 0 0 
// 0 1 0 0 0 1 0 
// 1 0 0 0 1 0 1 