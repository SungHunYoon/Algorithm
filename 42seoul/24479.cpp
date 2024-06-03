#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R, A, B;
vector<int> V[100001];
int D[100001];
int order = 1;

void dfs(int idx)
{
	D[idx] = order++;
	sort(V[idx].begin(), V[idx].end());
	for (int i = 0; i < V[idx].size(); i++)
	{
		if (D[V[idx][i]] == 0)
			dfs(V[idx][i]);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> R;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		V[A].push_back(B);
		V[B].push_back(A);
	}
	dfs(R);
	for (int i = 1; i <= N; i++)
		cout << D[i] << '\n';
	return 0;
}