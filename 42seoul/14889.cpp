#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int S[21][21];
bool V[21];
int answer = 1e9;

void dfs(vector<int> v, int idx)
{
	if (idx >= N)
		return;
	if (v.size() >= N / 2)
	{
		fill(V, V + N + 1, false);
		for (int i = 0; i < v.size(); i++)
			V[v[i]] = true;
		int A = 0, B = 0;
		for (int i = 0; i < v.size(); i++)
			for (int j = 0; j < v.size(); j++)
				A += S[v[i]][v[j]];
		v.clear();
		for (int i = 0; i < N; i++)
		{
			if (!V[i])
				v.push_back(i);
		}
		for (int i = 0; i < v.size(); i++)
			for (int j = 0; j < v.size(); j++)
				B += S[v[i]][v[j]];
		answer = min(answer, abs(A - B));
		return;
	}
	dfs(v, idx + 1);
	v.push_back(idx);
	dfs(v, idx + 1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> S[i][j];
	vector<int> v;
	dfs(v, 0);
	cout << answer << '\n';
	return 0;
}