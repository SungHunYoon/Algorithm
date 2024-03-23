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
	int tmp;
	while (cin >> tmp)
	{
		if (tmp == -1)
			break;
		if (q.size() == N && tmp != 0)
			continue;
		if (tmp == 0)
			q.pop();
		else
			q.push(tmp);
	}
	if (q.empty())
		cout << "empty\n";
	else
	{
		while (!q.empty())
		{
			cout << q.front() << ' ';
			q.pop();
		}
		cout << '\n';
	}
	return 0;
}