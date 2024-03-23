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
	int seq = 1;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (seq == tmp)
		{
			seq++;
			while (!stk.empty())
			{
				if (stk.top() != seq)
					break;
				seq++;
				stk.pop();
			}
		}
		else
		{
			while (!stk.empty())
			{
				if (stk.top() != seq)
					break;
				seq++;
				stk.pop();
			}
			stk.push(tmp);
		}
	}
	if (stk.empty())
		cout << "Nice\n";
	else
		cout << "Sad\n";
	return 0;
}
