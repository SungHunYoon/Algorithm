#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
map<string, int> m;
vector<pair<string, int> > answer;

bool cmp(const pair<string, int> &l, const pair<string, int> &r)
{
	if (l.second != r.second)
		return l.second > r.second;
	else if (l.first.length() != r.first.length())
		return l.first.length() > r.first.length();
	else
		return l.first < r.first;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		if (tmp.length() >= M)
		{
			if (m.find(tmp) == m.end())
				m.insert(make_pair(tmp, 0));
			else
				m[tmp]++;
		}
	}
	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
		answer.push_back(make_pair((*it).first, (*it).second));
	sort(answer.begin(), answer.end(), cmp);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i].first << '\n';
	return 0;
}