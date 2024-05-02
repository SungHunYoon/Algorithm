#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
pair<int, int> arr[1000001];
priority_queue<int, vector<int>, greater<int>> pq;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		while (!pq.empty() && pq.top() <= arr[i].first)
			pq.pop();
		pq.push(arr[i].second);
		answer = max(answer, (int)pq.size());
	}
	cout << answer << '\n';
	return 0;
}