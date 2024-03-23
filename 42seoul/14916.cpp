#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[100001];

int recursive(int num)
{
	if (num < 0)
		return -1;
	else if (num <= 5)
		return dp[num];
	else if (dp[num] != -10)
		return dp[num];
	int num2 = recursive(num - 2);
	int num5 = recursive(num - 5);
	if (num2 == -1 && num5 == -1)
		dp[num] = -1;
	else if (num5 != -1)
		dp[num] = num5 + 1;
	else if (num2 != -1)
		dp[num] = num2 + 1;
	return dp[num];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	fill(dp, dp + N + 1, -10);
	dp[0] = -1;
	dp[1] = -1;
	dp[2] = 1;
	dp[3] = -1;
	dp[4] = 2;
	dp[5] = 1;
	cout << recursive(N) << '\n';

	return 0;
}