#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;
int C[300001];
pair<int, int> J[300001];
priority_queue<int> pq;
long long answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> J[i].first >> J[i].second;
	for (int i = 0; i < K; i++)
		cin >> C[i];
	sort(J, J + N);
	// for (int i = 0; i < N; i++)
	// 	cout << J[i].first << " " << J[i].second << '\n';
	sort(C, C + K);
	int idx = 0;
	for (int i = 0; i < K; i++)
	{
		for (int j = idx; j < N && C[i] >= J[j].first; j++, idx++)
			pq.push(J[j].second);
		if (!pq.empty())
		{
			int p = pq.top(); pq.pop();
			answer += p;
		}
	}
	cout << answer << '\n';
	return 0;
}

// 100 100
// 5 10

// 11