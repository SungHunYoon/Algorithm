#include <iostream>
#include <set>

using namespace std;

int N, M;
set<int> a;
set<int> b;
set<int> answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		a.insert(tmp);
	}
	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		b.insert(tmp);
	}

	for (auto it = a.begin(); it != a.end(); it++)
	{
		if (b.find(*it) == b.end())
			answer.insert((*it));
	}
	cout << answer.size() << '\n';
	for (auto it = answer.begin(); it != answer.end(); it++)
		cout << (*it) << ' ';
	cout << '\n';
	return 0;
}