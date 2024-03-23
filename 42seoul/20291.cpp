#include <iostream>
#include <string>
#include <map>

using namespace std;

int N;
map<string, int> m;

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
		size_t pos = tmp.find('.');
		tmp = tmp.substr(pos + 1, tmp.size() - pos + 1);
		if (m.find(tmp) == m.end())
			m.insert({tmp, 1});
		else
			m[tmp]++;
	}
	for (auto it = m.begin(); it != m.end(); it++)
		cout << (*it).first << ' ' << (*it).second << '\n';

	return 0;
}