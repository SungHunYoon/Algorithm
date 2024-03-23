#include <iostream>
#include <algorithm>
#include <climits>

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
	//dp[2] = arr[1] == 0 ? INT_MAX - 1 : 1;
	for (int i = 2; i <= N; i++)
	{
		dp[i] = INT_MAX - 1;
		for (int j = 1; j < i; j++)
		{
			if (i - j <= arr[j])
				dp[i] = min(dp[i], dp[j] + 1);
		}
	}
	// for (int i = 1; i <= N; i++)
	// 	cout << dp[i] << '\n';
	cout << (dp[N] == INT_MAX - 1 ? -1 : dp[N]) << '\n';
	return 0;
}