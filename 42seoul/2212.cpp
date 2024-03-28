#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
int arr[10001];
priority_queue<int> pq;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N - 1; i++)
		pq.push(arr[i + 1] - arr[i]);
	for (int i = 0; i < K - 1; i++)
	{
		if (!pq.empty())
			pq.pop();
	}
	long long answer = 0;
	while (!pq.empty())
	{
		answer += pq.top();
		pq.pop();
	}
	cout << answer << '\n';
	return 0;
}

// 1 3 6 6 7 9
// [1, 3], [6, 9]

// 2 3

// 2 3 0 1 2

// 3 6 7 8 10 12 14 15 18 20
// [3, 3], [6, 8], [10, 15], [18, 18], [20, 20]
// [3, 3], [6, 10], [12, 15], [18, 18], [20, 20]

// 0 2 5 0 0
// 0 4 3 0 0

// 3 1 1 2 2 2 1 3 2
// 1 1 2 2 1
