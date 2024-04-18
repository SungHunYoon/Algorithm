#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, L, P;
pair<int, int> arr[10001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	cin >> L >> P;
	sort(arr, arr + N);
	int answer = 0;
	priority_queue<int> pq;
	for (int i = 0; i < N && P < L;)
	{
		while (i < N)
		{
			if (P < arr[i].first)
				break;
			pq.push(arr[i].second);
			i++;
		}
		if (!pq.empty())
		{
			P += pq.top();
			answer++;
			pq.pop();
		}
		else
			break;
	}
	if (P < L)
		cout << "-1\n";
	else
		cout << answer << '\n';
	return 0;
}
