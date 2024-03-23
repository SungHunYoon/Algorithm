#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	if (N == 1)
	{
		cout << "SK\n";
		return 0;
	}
	dp[0] = max(N - 1, N - 3);
	int i;
	for (i = 1; i < N; i++)
	{
		if (dp[i - 1] - 3 < 0)
			dp[i] = dp[i - 1] - 1;
		else
			dp[i] = max(dp[i - 1] - 1, dp[i - 1] - 3);
		if (dp[i] == 0)
			break;
	}
	if (i % 2 == 0)
		cout << "SK\n";
	else
		cout << "CY\n";
	return 0;
}

