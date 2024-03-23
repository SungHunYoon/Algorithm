#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

string S, E, Q;
map<string, int> m;
set<string> answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> S >> E >> Q;
	string history;
	while (getline(cin, history))
	{
		string time;
		string name;
		size_t pos = history.find(' ');
		time = history.substr(0, pos);
		name = history.substr(pos + 1, history.size() - pos + 1);
		if (S >= time)
			m[name] = 1;
		if (E <= time && Q >= time)
		{
			if (m.find(name) != m.end())
				answer.insert(name);
		}
	}
	cout << answer.size() << '\n';

	return 0;
}