#include <iostream>
#include <algorithm>

using namespace std;

int K;
pair<int, int> dp[46];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> K;
	dp[1] = {0, 1};
	dp[2] = {1, 1};
	for (int i = 3; i <= K; i++)
	{
		dp[i].first = dp[i - 1].first + dp[i - 2].first;
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}
	cout << dp[K].first << " " << dp[K].second << '\n';
	return 0;
}