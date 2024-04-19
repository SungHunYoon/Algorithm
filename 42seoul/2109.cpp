#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
pair<int, int> arr[10001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].second >> arr[i].first;
	sort(arr, arr + N);
	// for (int i = 0; i < N; i++)
	// 	cout << arr[i].first << " " << arr[i].second << '\n';
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++)
	{
		if (arr[i].first > pq.size())
			pq.push(arr[i].second);
		else
		{
			if (arr[i].second > pq.top())
			{
				pq.pop();
				pq.push(arr[i].second);
			}
		}
	}
	int answer = 0;
	while (!pq.empty())
	{
		answer += pq.top();
		pq.pop();
	}
	cout << answer << '\n';
	return 0;
}
