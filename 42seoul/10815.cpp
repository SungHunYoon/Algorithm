#include <iostream>
#include <set>

using namespace std;

int N, M;
set<int> s;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		s.insert(tmp);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		set<int>::iterator it = s.find(tmp);
		if (it != s.end())
			cout << "1";
		else
			cout << "0";
		cout << " ";
	}
	cout << '\n';

	return 0;
}