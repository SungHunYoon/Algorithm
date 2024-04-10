#include <iostream>
#include <string>
#include <climits>

using namespace std;

string str;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int idx = 1;
	while (cin >> str)
	{
		if (str[0] == '-')
			break;
		int answer = 0;
		int frontCnt = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '{')
				frontCnt++;
			else
			{
				if (frontCnt == 0)
				{
					answer++;
					frontCnt++;
				}
				else
					frontCnt--;
			}
		}
		answer += frontCnt / 2;
		cout << idx << ". " << answer << '\n';
		idx++;
	}
	return 0;
}