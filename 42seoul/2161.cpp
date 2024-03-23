#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> q;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		q.push(i);
	
	while (!q.empty())
	{
		cout << q.front() << ' ';
		q.pop();
		if (q.empty())
			break;
		int tmp = q.front();
		q.pop();
		q.push(tmp);
	}
	return 0;
}