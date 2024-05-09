#include <iostream>
#include <algorithm>

using namespace std;
using LL = long long;

int N;
LL arr[250001];
LL dp[2][250001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	dp[0][1] = arr[1];
	bool flag = true;
	if (dp[0][1] == 0)
	{
		dp[0][1] = 1;
		flag = false;
	}
	for (int i = 2; i <= N; i++)
	{
		if (arr[i] != 0)
		{
			dp[0][i] = dp[0][i - 1] + arr[i];
			flag = true;
		}
		else if (flag)
		{
			dp[0][i] = dp[0][i - 1] + 1;
			flag = false;
		}
		else
			dp[0][i] = max(dp[0][i - 2] + 1, dp[0][i - 1]);
	}
	flag = true;
	for (int i = 2; i <= N; i++)
	{
		if (arr[i] != 0)
		{
			dp[1][i] = dp[1][i - 1] + arr[i];
			flag = true;
		}
		else if (flag)
		{
			dp[1][i] = dp[1][i - 1] + 1;
			flag = false;
		}
		else
			dp[1][i] = max(dp[1][i - 2] + 1, dp[1][i - 1]);
	}
	if (arr[1] == 0 && arr[N] == 0)
		cout << max(dp[0][N - 1], dp[1][N]) << '\n';
	else
		cout << max(dp[0][N], dp[1][N]) << '\n';
	return 0;
}