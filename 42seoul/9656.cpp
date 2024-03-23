#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	if (N == 1)
	{
		cout << "CY\n";
		return 0;
	}
	dp[0] = max(N - 1, N - 3);
	int i = 1;
	while (i < N)
	{
		dp[i] = max(dp[i - 1] - 1, dp[i - 1] - 3);
		if (dp[i] == 0)
			break;
		i++;
	}
	if (i % 2 == 0)
		cout << "CY\n";
	else
		cout << "SK\n";
	return 0;
}