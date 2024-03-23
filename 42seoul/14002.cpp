#include <iostream>
#include <set>

using namespace std;

int N;
int arr[1001];
int dp[1001];
int trace[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	dp[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = i - 1; j >= 1; j--)
		{
			if (arr[j] < arr[i])
			{
				if (dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
					trace[i] = j;
				}
			}
		}
		if (dp[i] == 0)
			dp[i] = 1;
	}
	int max = dp[1];
	int maxIndex = 1;
	for (int i = 2; i <= N; i++)
	{
		if (max < dp[i])
		{
			max = dp[i];
			maxIndex = i;
		}
	}
	cout << dp[maxIndex] << '\n';
	set<int> answer;
	while (trace[maxIndex] != 0)
	{
		answer.insert(arr[maxIndex]);
		maxIndex = trace[maxIndex];
	}
	answer.insert(arr[maxIndex]);
	for (auto it = answer.begin(); it != answer.end(); it++)
		cout << (*it) << ' ';
	cout << '\n';
	return 0;
}