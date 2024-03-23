#include <iostream>
#include <string>
#include <set>

using namespace std;

int N;
set<string> s;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	s.insert("ChongChong");
	for (int i = 0; i < N; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if (s.find(s1) != s.end())
			s.insert(s2);
		else if (s.find(s2) != s.end())
			s.insert(s1);
	}
	cout << s.size() << '\n';

	return 0;
}