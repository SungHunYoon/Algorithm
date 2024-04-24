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
    int sum = m.rbegin()->second - 1;
	int ret = m.rbegin()->first + sum;
	for (auto it = next(m.rbegin()); it != m.rend(); it++)
    {
        sum += it->second;
        ret = max(ret, it->first + sum);
    }
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
