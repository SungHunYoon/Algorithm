#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int K, L;
map<string, int> m;
vector<pair<string ,int> > answer;

bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
	return a.second < b.second;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> K >> L;
	for (int i = 0; i < L; i++)
	{
		string num;
		cin >> num;
		m[num] = i;
	}
	for (auto it = m.begin(); it != m.end(); it++)
		answer.push_back(*it);
	sort(answer.begin(), answer.end(), cmp);
	for (int i = 0; i < K && i < answer.size(); i++)
		cout << answer[i].first << '\n';
	return 0;
}