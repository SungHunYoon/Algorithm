#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int N, K;
set<string> visit;
queue<string> q;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	string str;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		str.append(1, num + '0');
	}

	q.push(str);
	visit.insert(str);
	int cnt = 0;
	while (!q.empty())
	{
		int len = q.size();
		for (int i = 0; i < len; i++)
		{
			string s = q.front();
			q.pop();

			bool isSorted = true;
			int prev = 0;
			for (int j = 0; j < s.size(); j++)
			{
				if (prev < s[j] - '0')
					prev = s[j] - '0';
				else
					isSorted = false;
			}
			if (isSorted)
			{
				cout << cnt << '\n';
				return 0;
			}
			for (int j = 0; j < s.size(); j++)
			{
				if (j + K > s.size())
					break;
				string tmp = s;
				for (int k = 0; k < K / 2; k++)
					swap(tmp[j + k], tmp[j + (K - k - 1)]);
				if (visit.insert(tmp).second)
				 	q.push(tmp);
			}
		}
		cnt++;
	}
	cout << "-1\n";
	return 0;
}
