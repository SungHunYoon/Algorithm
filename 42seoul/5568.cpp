#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int N, K;
vector<int> vec(11);
set<string> s;

void recursive(vector<int> comb, vector<bool> visit, int sel)
{
	if (sel >= K)
	{
		string str;
		for (int i = 0; i < comb.size(); i++)
			str.append(to_string(comb[i]));
		s.insert(str);
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (!visit[i])
		{
			comb.push_back(vec[i]);
			visit[i] = true;
			recursive(comb, visit, sel + 1);
			visit[i] = false;
			comb.pop_back();
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> vec[i];
	vector<int> comb;
	vector<bool> visit(N + 1);
	recursive(comb, visit, 0);
	cout << s.size() << '\n';
	return 0;
}