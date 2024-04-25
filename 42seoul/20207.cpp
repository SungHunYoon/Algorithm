#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
pair<int, int> arr[1001];
priority_queue<int, vector<int>, greater<int>> pq;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	int s = arr[0].first;
	int e = 0;
	int maxSize = 0;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		while (!pq.empty() && pq.top() < arr[i].first)
		{
			e = pq.top();
			pq.pop();
		}
		if (pq.empty() && e + 1 < arr[i].first)
		{
			answer += (e - s + 1) * maxSize;
			s = arr[i].first;
			maxSize = 0;
		}
		pq.push(arr[i].second);
		maxSize = max(maxSize, (int)pq.size());
	}
	if (!pq.empty())
	{
		while (!pq.empty())
		{
			e = pq.top();
			pq.pop();
		}
		answer += (e - s + 1) * maxSize;
	}
	cout << answer << '\n';
	return 0;
}