#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long dp[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> dp[i];
		dp[i] = max(dp[i], dp[i - 1] + dp[i]);
	}
	cout << *max_element(dp + 1, dp + N + 1) << '\n';

	return 0;
}