#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
pair<int, int> arr[10001];
int answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		//cout << arr[i].first << " " << arr[i].second << '\n';
		if (arr[i].first >= arr[i].second)
		{
			if (i + 1 < N)
				arr[i + 1].first = max(arr[i + 1].first, arr[i].first);
			continue;
		}
		int tmp = (arr[i].second - arr[i].first) / L;
		if ((arr[i].second - arr[i].first) % L != 0)
			tmp++;
		arr[i].second = arr[i].first + tmp * L;
		answer += tmp;
		if (i + 1 < N)
			arr[i + 1].first = max(arr[i + 1].first, arr[i].second);
	}
	cout << answer << '\n';
	return 0;
}

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
//   x x x x x   x        x  x  x  x
// 