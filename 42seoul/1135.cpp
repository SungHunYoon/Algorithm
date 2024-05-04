#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;
int arr[51];
vector<int> v[51];

int recursive(int idx)
{
	if (v[idx].empty())
		return 1;
	map<int, int> m;
	for (int i = 0; i < v[idx].size(); i++)
		m[recursive(v[idx][i])]++;
	int ret = 0;
	for (auto it = m.begin(); it != prev(m.end()); it++)
		ret += it->second;
	cout << m.rbegin()->first << " " << m.begin()->first + ret << '\n';
	ret = max(m.rbegin()->first, m.begin()->first + ret);
	return ret + 1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (i != 0)
			v[arr[i]].push_back(i);
	}
	cout << recursive(0) - 1 << '\n';
	return 0;
}
// 35
// -1 0 0 0 0 0 1 1 1 1 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5 6 6 6 6 6 6

// 5 4 4 5 5 6