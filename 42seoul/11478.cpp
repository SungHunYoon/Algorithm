#include <iostream>
#include <set>
#include <string>

using namespace std;

string S;
set<string> s;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> S;
	for (int i = 0; i < S.length(); i++)
	{
		for (int j = 0; j <= S.length() - i; j++)
		{
			string tmp = S.substr(i, j);
			if (!tmp.empty())
				s.insert(tmp);
		}
	}
	cout << s.size() << '\n';
	return 0;
}