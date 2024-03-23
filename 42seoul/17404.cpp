#include <iostream>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

int N;
int arr[3][1001];
int dp[3][1001];
int trace[3][1001];
multiset<pair<int, int>> answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[0][i] >> arr[1][i] >> arr[2][i];

	dp[0][N] = arr[0][N];
	dp[1][N] = arr[1][N];
	dp[2][N] = arr[2][N];

	trace[0][0] = 0;
	trace[1][0] = 1;
	trace[2][0] = 2;

	trace[0][N] = 0;
	trace[1][N] = 1;
	trace[2][N] = 2;

	for (int i = N - 1; i >= 1; i--)
	{
		dp[0][i] = min(dp[1][i + 1], dp[2][i + 1]) + arr[0][i];
		trace[0][i] = dp[1][i + 1] <= dp[2][i + 1] ? 1 : 2;
		dp[1][i] = min(dp[0][i + 1], dp[2][i + 1]) + arr[1][i];
		trace[1][i] = dp[0][i + 1] <= dp[2][i + 1] ? 0 : 2;
		dp[2][i] = min(dp[0][i + 1], dp[1][i + 1]) + arr[2][i];
		trace[2][i] = dp[0][i + 1] <= dp[1][i + 1] ? 0 : 1;
	}

	// cout << "----------------\n";
	// for (int i = 1; i <= N; i++)
	// {
	// 	cout << dp[0][i] << " " << dp[1][i] << " " << dp[2][i] << '\n';
	// 	cout << trace[0][i] << " " << trace[1][i] << " " << trace[2][i] << '\n';
	// 	cout << '\n';
	// }

	answer.insert({dp[0][1], trace[0][0]});
	answer.insert({dp[1][1], trace[1][0]});
	answer.insert({dp[2][1], trace[2][0]});

	int a = INT_MAX;
	for (auto it = answer.begin(); it != answer.end(); it++)
	{
		int result = trace[it->second][0];
		for (int i = 1; i < N; i++)
			result = trace[result][i];
		if (trace[result][N] != it->second)
		{
			a = min(a, it->first);
			break;
		}
	}

	dp[0][1] = arr[0][1];
	dp[1][1] = arr[1][1];
	dp[2][1] = arr[2][1];

	for (int i = 2; i <= N; i++)
	{
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + arr[0][i];
		trace[0][i] = dp[1][i - 1] <= dp[2][i - 1] ? 1 : 2;
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + arr[1][i];
		trace[1][i] = dp[0][i - 1] <= dp[2][i - 1] ? 0 : 2;
		dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + arr[2][i];
		trace[2][i] = dp[0][i - 1] <= dp[1][i - 1] ? 0 : 1;
	}

	// cout << "----------------\n";
	// for (int i = 1; i <= N; i++)
	// {
	// 	cout << dp[0][i] << " " << dp[1][i] << " " << dp[2][i] << '\n';
	// 	cout << trace[0][i] << " " << trace[1][i] << " " << trace[2][i] << '\n';
	// 	cout << '\n';
	// }

	answer.clear();

	answer.insert({dp[0][N], trace[0][0]});
	answer.insert({dp[1][N], trace[1][0]});
	answer.insert({dp[2][N], trace[2][0]});

	for (auto it = answer.begin(); it != answer.end(); it++)
	{
		int result = trace[it->second][0];
		for (int i = N; i > 1; i--)
		{
			//cout << result << '\n';
			result = trace[result][i];
		}
		//cout << it->first << " " << result << " " << it->second << '\n';
		if (trace[result][0] != it->second)
		{
			a = min(a, it->first);
			break;
		}
	}

	cout << a << '\n';
	return 0;
}