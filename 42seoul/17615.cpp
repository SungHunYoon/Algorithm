#include <iostream>
#include <string>

using namespace std;

int N;
string str;

int checkMove(bool isReverse, bool isRed)
{
	int ret = 0;
	int cnt = 0;
	if (!isReverse)
	{
		for (int i = str.size() - 1; i >= 0; i--)
		{
			if (str[i] != (isRed ? 'R' : 'B'))
				cnt++;
			else
			{
				if (cnt != 0)
					ret++;
			}
		}
	}
	else
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != (isRed ? 'R' : 'B'))
				cnt++;
			else
			{
				if (cnt != 0)
					ret++;
			}
		}
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> str;
	int answer = checkMove(false, false);
	answer = min(answer, checkMove(true, false));
	answer = min(answer, checkMove(false, true));
	answer = min(answer, checkMove(true, true));
	cout << answer << '\n';
	return 0;
}

// R R R B B B B B R R B B R R R R
