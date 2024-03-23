#include <iostream>
#include <algorithm>

using namespace std;

int N, X;
pair<int, int> arr[100001];
int answer;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
	int gapA = a.first - a.second;
	int gapB = b.first - b.second;
	if (gapA != gapB)
		return gapA > gapB;
	return a.first < a.second;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> X;
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N, cmp);
	// for (int i = 0; i < N; i++)
	// 	cout << arr[i].first << " " << arr[i].second << '\n';
	for (int i = 0; i < N; i++)
	{
		if (arr[i].first <= arr[i].second)
		{
			X -= 1000;
			answer += arr[i].second;
		}
		else if (arr[i].first > arr[i].second && X - 5000 >= 1000 * (N - i - 1))
		{
			X -= 5000;
			answer += arr[i].first;
		}
		else
		{
			X -= 1000;
			answer += arr[i].second;
		}
	}
	cout << answer << '\n';
	return 0;
}
