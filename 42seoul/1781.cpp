#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
pair<int, int> arr[200001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++)
	{
		if (pq.empty())
			pq.push(arr[i].second);
		else
		{
			if (arr[i].first - pq.size() > 0)
				pq.push(arr[i].second);
			else if (pq.top() < arr[i].second)
			{
				pq.pop();
				pq.push(arr[i].second);
			}
		}
		//cout << pq.top() << '\n';
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