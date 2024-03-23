#include <iostream>
#include <string>
#include <set>

using namespace std;

int R, C;
string str[1001];
int answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			char c;
			cin >> c;
			str[j].append(1, c);
		}
	}

	for (int k = 0; k < R; k++)
	{
		bool flag = false;
		set<string> s;
		for (int i = 0; i < C; i++)
		{
			string tmp = str[i].substr(k, R - k);
			if (s.find(tmp) == s.end())
				s.insert(str[i].substr(k, R - k));
			else
			{
				flag = true;
				break;
			}
		}
		if (flag)
			break;
		answer++;
	}
	cout << answer - 1 << '\n';

	return 0;
}