#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
priority_queue<long long, vector<long long>, greater<long long> > pq;
long long answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	for (int i = 0; i < M; i++)
	{
		long long x = pq.top();
		pq.pop();
		long long y = pq.top();
		pq.pop();	
		pq.push(x + y);
		pq.push(x + y);
	}

	while (!pq.empty())
	{
		answer += pq.top();
		pq.pop();
	}
	cout << answer << '\n';
	return 0;
}