#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, A, B, X, Y;
bool C[10001];
int answer = 0;

int dfs(vector<int> V[10001], vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (!C[v[i]])
		{
			C[v[i]] = true;
			if (dfs(V, V[v[i]]))
				return 1;
		}
		else
		{
			answer = v[i];
			return 1;
		}
	}
	return 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<int> V[10001];
		fill(C, C + N + 1, false);
		for (int i = 0; i < N - 1; i++)
		{
			cin >> A >> B;
			V[B].push_back(A);
		}
		cin >> X >> Y;
		// cout << X << " " << Y << '\n';
		// for (int i = 0; i < V[X].size(); i++)
		// 	cout << V[X][i] << ' ';
		// cout << '\n';
		C[X] = true;
		dfs(V, V[X]);
		dfs(V, V[Y]);
		cout << answer << '\n';
	}

	return 0;
}