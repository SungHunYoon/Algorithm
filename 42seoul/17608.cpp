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
		int tmp;
		cin >> tmp;
		if (stk.empty())
			stk.push(tmp);
		else
		{
			while (!stk.empty())
			{
				if (stk.top() > tmp)
					break;
				stk.pop();
			}
			stk.push(tmp);
		}
	}
	cout << stk.size() << '\n';
	return 0;
}