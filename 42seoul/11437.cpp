#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, A, B;
int P[50001];
int D[50001];
vector<int> V[50001];

void dfs(int prev, int depth)
{
	depth++;
	for (int i = 0; i < V[prev].size(); i++)
	{
		if (D[V[prev][i]] == 0)
		{
			P[V[prev][i]] = prev;
			D[V[prev][i]] = depth;
			dfs(V[prev][i], depth);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> A >> B;
		V[A].push_back(B);
		V[B].push_back(A);
	}
	D[1] = 1;
	dfs(1, 1);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		if (D[A] < D[B])
			swap(A, B);
		while (D[A] != D[B])
			A = P[A];
		while (A != B)
		{
			A = P[A];
			B = P[B];
		}
		cout << A << '\n';
	}
	return 0;
}
