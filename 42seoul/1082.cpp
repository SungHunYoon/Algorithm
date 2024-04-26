#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
int arr[11];
string dp[51];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> M;
	for (int i = 1; i <= M; i++)
	{
		for (int j = N - 1; j >= 0; j--)
		{
			if (i - arr[j] >= 0)
			{
				string t = dp[i - arr[j]] + to_string(j);
				if (dp[i].size() < t.size())
					dp[i] = t;
				else if (dp[i].size() == t.size())
					dp[i] = max(dp[i], t);
			}
			if (dp[i].empty() || dp[i][0] == '0')
				dp[i] = dp[i - 1];
		}
	}
	if (dp[M].empty())
		dp[M] = "0";
	cout << dp[M] << '\n';
	return 0;
}