#include <iostream>

using namespace std;

int T, N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		int arr[N];
		long long answer = 0;
		int maxValue = 0;
		int maxIndex = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> arr[j];
			if (maxValue <= arr[j])
			{
				maxValue = arr[j];
				maxIndex = j;
			}
		}
		int startIndex = 0;
		while (1)
		{
			//cout << maxValue << '\n';
			for (int j = startIndex; j < maxIndex; j++)
				answer += arr[maxIndex] - arr[j];
			startIndex = maxIndex + 1;
			if (startIndex == N)
				break;
			maxValue = 0;
			for (int j = maxIndex + 1; j < N; j++)
			{
				if (maxValue <= arr[j])
				{
					maxValue = arr[j];
					maxIndex = j;
				}
			}
		}
		cout << answer << '\n';
	}

	return 0;
}