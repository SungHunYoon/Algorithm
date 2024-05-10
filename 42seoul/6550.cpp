#include <iostream>
#include <string>

using namespace std;

string S, T;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> S >> T)
	{
		bool flag = false;
		for (int i = 0, idx = 0; i < T.size(); i++)
		{
			if (T[i] == S[idx])
			{
				idx++;
				if (idx == S.size())
				{
					flag = true;
					break;
				}
			}
		}
		if (flag)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}