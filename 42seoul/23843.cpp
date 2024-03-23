#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int arr[10001];
priority_queue<int, vector<int>, greater<int>> pq;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = N - 1; i >= 0; i--)
	{
		if (pq.size() < M)
			pq.push(arr[i]);
		else
		{
			int tmp = pq.top();
			pq.pop();
			tmp += arr[i];
			pq.push(tmp);
		}
	}
	while (pq.size() > 1)
		pq.pop();
	cout << pq.top() << '\n';
	return 0;
}