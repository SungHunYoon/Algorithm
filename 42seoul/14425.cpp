#include <iostream>
#include <string>
#include <set>

using namespace std;

int N, M;
set<string> s;
int answer;

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
		s.insert(tmp);
	}
	for (int i = 0; i < M; i++)
	{
		string tmp;
		cin >> tmp;
		if (s.find(tmp) != s.end())
			answer++;
	}
	cout << answer << '\n';

	return 0;
}