#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int> > pq;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	int Nsqaure = N * N;
	for (int i = 0; i < Nsqaure; i++)
	{
		int tmp;
		cin >> tmp;
		pq.push(tmp);
		if (pq.size() > N)
			pq.pop();
	}
	cout << pq.top() << '\n';
	return 0;
}