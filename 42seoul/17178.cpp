#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N;
set<string> s;
vector<string> vec;
vector<int> indexing(500);
stack<int> stk;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			string tmp;
			cin >> tmp;
			if (tmp.length() == 3)
				tmp.insert(2, "00");
			else if (tmp.length() == 4)
				tmp.insert(2, "0");
			s.insert(tmp);
			vec.push_back(tmp);
		}
	}
	int idx = 0;
	for (set<string>::iterator it = s.begin(); it != s.end(); it++)
	{
		int i = find(vec.begin(), vec.end(), *it) - vec.begin();
		indexing[i] = idx;
		idx++;
	}

	idx = 0;
	for (int i = 0; i < N * 5; i++)
	{
		if (indexing[i] != idx)
			stk.push(indexing[i]);
		else
		{
			idx++;
			while (!stk.empty())
			{
				if (stk.top() != idx)
					break;
				stk.pop();
				idx++;
			}
		}
	}
	if (stk.empty())
		cout << "GOOD\n";
	else
		cout << "BAD\n";
	return 0;
}