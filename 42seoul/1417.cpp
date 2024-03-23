#include <iostream>
#include <queue>

using namespace std;

int N;
int standard;
priority_queue<int> pq;
int answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> standard;
	for (int i = 1; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}
	while (!pq.empty())
	{
		int t = pq.top();
		pq.pop();
		if (t >= standard)
		{
			t--;
			standard++;
			pq.push(t);
			answer++;
		}
	}
	cout << answer << '\n';

	return 0;
}