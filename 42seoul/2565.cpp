#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[501];
int dp[501];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}
	dp[1] = 1;
	for (int i = 2; i <= 500; i++)
	{
		if (arr[i] == 0)
			continue;
		for (int j = i - 1; j >= 1; j--)
		{
			if (arr[j] == 0)
				continue;
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		if (dp[i] == 0)
			dp[i] = 1;
	}
	cout << N - *max_element(dp, dp + 501) << '\n';
	return 0;
}