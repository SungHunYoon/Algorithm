#include <iostream>
#include <set>

using namespace std;

int T, N, M;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		set<int> s;
		for (int j = 0; j < N; j++)
		{
			int tmp;
			cin >> tmp;
			s.insert(tmp);
		}

		cin >> M;
		for (int j = 0; j < M; j++)
		{
			int tmp;
			cin >> tmp;
			if (s.find(tmp) != s.end())
				cout << "1\n";
			else
				cout << "0\n";
		}
	}

	return 0;
}