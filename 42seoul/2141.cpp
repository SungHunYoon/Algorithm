#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
pair<int, int> arr[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		sum += arr[i].second;
	}
	sort(arr, arr + N);
	sum = (sum + 1) / 2;
	long long presum = 0;
	for (int i = 0; i < N; i++)
	{
		presum += arr[i].second;
		if (sum <= presum)
		{
			cout << arr[i].first << '\n';
			break;
		}
	}
	return 0;
}
