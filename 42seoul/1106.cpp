#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int C, N;
pair<int, int> arr[21];
int dp[1501];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> C >> N;
	pair<int, int> minPair = {INT_MAX, INT_MAX};
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		if (arr[i].second < minPair.second)
			minPair = arr[i];
	}
	sort(arr, arr + N + 1);
	int answer = minPair.first * ((C / minPair.second) + (C % minPair.second != 0 ? 1 : 0));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 1500; j++)
		{
			if (j - arr[i].first >= 0)
			{
				dp[j] = max(dp[j], dp[j - arr[i].first] + arr[i].second);
				if (dp[j] >= C)
					answer = min(answer, j);
			}
			//cout << dp[j] << ' ';
		}
		//cout << '\n';
	}
	cout << answer << '\n';
	return 0;
}

// 12 2
// 3 5
// 1 1

// dp[5] = 3;
// dp[6] = INF;
// dp[7] = INF;
// dp[8] = INF;
// dp[9] = INF;
// dp[10] = 6;
// dp[11] = INF;
// dp[12] = INF;
// ...

// dp[1] = 1;
// dp[2] = 2;
// dp[3] = 3;
// dp[4] = 4;
// dp[5] = 3;
// dp[6] = 4;
// dp[7] = 5;
// dp[8] = 6;
// dp[9] = 7;
// dp[10] = 6;
// dp[11] = 7;
// dp[12] = 8;
// ...
