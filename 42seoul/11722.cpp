#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1001];
int arr[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	dp[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = i - 1; j >= 1; j--)
		{
			if (arr[j] > arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		if (dp[i] == 0)
			dp[i] = 1;
	}
	cout << *max_element(dp, dp + N + 1) << '\n';
	return 0;
}