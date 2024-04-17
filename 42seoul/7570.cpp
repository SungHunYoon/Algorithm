#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000001];
int dp[1000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++)
	{
		if (dp[arr[i] - 1] != 0)
			dp[arr[i]] = dp[arr[i] - 1] + 1;
		else
			dp[arr[i]] = 1;
	}
	cout << N - *max_element(dp, dp + N + 1) << '\n';
	return 0;
}
