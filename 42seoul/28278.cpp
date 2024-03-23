#include <iostream>
#include <stack>

using namespace std;

int N;
stack<int> stk;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)
		{
			int num;
			cin >> num;
			stk.push(num);
		}
		else if (cmd == 2)
		{
			if (stk.empty())
				cout << "-1\n";
			else
			{
				cout << stk.top() << '\n';
				stk.pop();
			}
		}
		else if (cmd == 3)
			cout << stk.size() << '\n';
		else if (cmd == 4)
			cout << stk.empty() << '\n';
		else
		{
			if (stk.empty())
				cout << "-1\n";
			else
				cout << stk.top() << '\n';
		}
	}

	return 0;
}