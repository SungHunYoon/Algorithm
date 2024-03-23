#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[1001][1001];
int dp[1001][1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1])) + arr[i][j];
	cout << dp[N][M] << '\n';
	return 0;
}