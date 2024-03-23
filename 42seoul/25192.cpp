#include <iostream>
#include <string>
#include <set>

using namespace std;

int N;
set<string> s;
int answer;

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
		if (tmp == "ENTER")
			s.clear();
		else
		{
			if (s.find(tmp) == s.end())
			{
				s.insert(tmp);
				answer++;
			}
		}
	}
	cout << answer << '\n';

	return 0;
}