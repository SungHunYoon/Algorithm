#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001];
int dp[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	for (int i = 1; i <= N; i++)
		dp[i] = dp[i - 1] + arr[1];
	for (int i = 2; i <= N; i++)
		for (int j = i; j <= N; j++)
			dp[j] = min(dp[j], dp[j - i] + arr[i]);
	cout << dp[N] << '\n';
	return 0;
}