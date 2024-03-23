#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> m;
int total;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	while (getline(cin, str))
	{
		if (m.find(str) == m.end())
			m.insert({str, 1});
		else
			m[str]++;
		total++;
	}
	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << fixed;
		cout.precision(4);
		cout << (*it).first << " " << ((double)(*it).second / total) * 100 << '\n';
	}

	return 0;
}