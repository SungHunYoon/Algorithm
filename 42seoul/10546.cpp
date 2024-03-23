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
		if (m.find(tmp) == m.end())
			m.insert({tmp, 1});
		else
			m[tmp]++;
	}
	for (int i = 0; i < N - 1; i++)
	{
		string tmp;
		cin >> tmp;
		auto it = m.find(tmp);
		if (--(*it).second == 0)
			m.erase(it);
	}
	cout << (m.begin())->first << '\n';

	return 0;
}