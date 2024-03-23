#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int T, K;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> K;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for (int j = 0; j < K; j++)
		{
			int num;
			cin >> num;
			pq.push(num);
		}
		long long answer = 0;
		while (pq.size() > 1)
		{
			long long tmp1 = pq.top(); pq.pop();
			long long tmp2 = pq.top(); pq.pop();
			answer += tmp1 + tmp2;
			pq.push(tmp1 + tmp2);
		}
		cout << answer << '\n';
	}
	return 0;
}