#include <iostream>
#include <queue>

using namespace std;

int N, K;
int arr[100001];
priority_queue<int, vector<int>, greater<int>> pq;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	K--;
	int prev = arr[0];
	long long answer = 1;
	for (int i = 1; i < N; i++)
	{
		if (arr[i - 1] + 1 == arr[i])
		{
			prev = arr[i];
			answer++;
		}
		else if (K > 0)
		{
			pq.push(arr[i] - prev);
			prev = arr[i];
			K--;
			answer++;
		}
		else
		{
			pq.push(arr[i] - prev);
			int t = pq.top(); pq.pop();
			answer += t;
			prev = arr[i];
		}
	}
	cout << answer << '\n';
	return 0;
}
