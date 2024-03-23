#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int> > arr(1001);
int answer;

bool cmp(const pair<int, int> &l, const pair<int, int> &r)
{
	return l.second < r.second;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.begin() + N);
	int maxIndex = max_element(arr.begin(), arr.end(), cmp) - arr.begin();
	while (N - 1 > maxIndex && arr[maxIndex].second == arr[maxIndex + 1].second)
		maxIndex++;
	pair<int, int> b = arr[0];
	for (int i = 0; i < maxIndex - 1; i++)
	{
		if (arr[i + 1].second > b.second)
		{
			answer += b.second * (arr[i + 1].first - b.first);
			b = arr[i + 1];
		}
	}
	answer += b.second * (arr[maxIndex].first - b.first);
	b = arr[N - 1];
	for (int i = N - 1; i > maxIndex + 1; i--)
	{
		if (arr[i - 1].second > b.second)
		{
			answer += b.second * (b.first - arr[i - 1].first);
			b = arr[i - 1];
		}
	}
	answer += b.second * (b.first - arr[maxIndex].first);
	answer += arr[maxIndex].second;
	cout << answer << '\n';
	return 0;
}