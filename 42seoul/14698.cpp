#include <iostream>
#include <queue>

using namespace std;
using LL = long long;

int T, N;
LL arr[61];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		priority_queue<LL, vector<LL>, greater<LL>> pq;
		for (int j = 0; j < N; j++)
		{
			cin >> arr[j];
			pq.push(arr[j]);
		}
		LL answer = 1;
		while (pq.size() != 1)
		{
			LL a = pq.top(); pq.pop();
			LL b = pq.top(); pq.pop();
			LL cal = a * b;
			answer *= cal % 1000000007L;
			answer %= 1000000007L;
			pq.push(cal);
		}
		cout << answer << '\n';
	}
	return 0;
}
