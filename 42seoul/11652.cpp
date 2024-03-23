#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N;
map<long long, int> m;
pair<long long, int> answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		long long num;
		cin >> num;
		map<long long, int>::iterator it = m.find(num);
		if (it == m.end())
			m.insert(make_pair(num, 1));
		else
			(*it).second += 1;
	}
	for (map<long long, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		if (answer.second < (*it).second)
			answer = *it;
	}
	cout << answer.first << '\n';
	return 0;
}