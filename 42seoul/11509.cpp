#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000001];
int dp[1000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++)
	{
		dp[arr[i]]++;
		if (dp[arr[i] + 1] != 0)
			dp[arr[i] + 1]--;
	}
	int answer = 0;
	for (int i = 0; i < 1000001; i++)
		answer += dp[i];
	cout << answer << '\n';
	return 0;
}
