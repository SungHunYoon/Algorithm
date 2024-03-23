#include <iostream>
#include <string>
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
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		if (tmp == "push")
		{
			int num;
			cin >> num;
			q.push(num);
		}
		else if (tmp == "pop")
		{
			if (!q.empty())
			{
				cout << q.front() << '\n';
				q.pop();
			}
			else
				cout << "-1\n";
		}
		else if (tmp == "size")
			cout << q.size() << '\n';
		else if (tmp == "empty")
		{
			if (q.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (tmp == "front")
		{
			if (!q.empty())
				cout << q.front() << '\n';
			else
				cout << "-1\n";
		}
		else
		{
			if (!q.empty())
				cout << q.back() << '\n';
			else
				cout << "-1\n";
		}
	}

	return 0;
}