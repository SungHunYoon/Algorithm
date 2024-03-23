#include <iostream>
#include <algorithm>

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
		pair<int, int> arr[N];
		for (int j = 0; j < N; j++)
			cin >> arr[j].first >> arr[j].second;
		sort(arr, arr + N);
		pair<int, int> p = arr[0];
		int answer = 1;
		for (int j = 1; j < N; j++)
		{
			if (p.first > arr[j].first || p.second > arr[j].second)
			{
				p = arr[j];
				answer++;
			}
			//cout << p.first << " " << p.second << '\n';
		}
		cout << answer << '\n';
	}

	return 0;
}