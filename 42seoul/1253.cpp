#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[2001];
int answer[2001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (i == j)
				continue;
			int sum = arr[i] + arr[j];
			auto it = lower_bound(arr, arr + N, sum);
			if (it != arr + N && answer[it - arr] == 0)
			{
				while (it - i == arr || it - j == arr)
					it++;
				while (*it == sum)
				{
					answer[it - arr] = 1;
					it++;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++)
		cnt += answer[i];
	cout << cnt << '\n';
	return 0;
}