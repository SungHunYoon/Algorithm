#include <iostream>
#include <algorithm>

using namespace std;

int N, C, M;
pair<pair<int, int>, int> arr[10001];
int dp[2001];

bool compare(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
{
	if (a.first.second == b.first.second)
		return a.first.first < b.first.first;
	return a.first.second < b.first.second;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> C >> M;
	for (int i = 0; i < M; i++)
		cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
	sort(arr, arr + M, compare);
	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		int maxDp = 0;
		for (int j = arr[i].first.first; j < arr[i].first.second; j++)
			maxDp = max(maxDp, dp[j]);
		int capacity = min(arr[i].second, C - maxDp);
		for (int j = arr[i].first.first; j < arr[i].first.second; j++)
			dp[j] += capacity;
		answer += capacity;
	}
	cout << answer << '\n';
	return 0;
}
