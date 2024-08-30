#include <iostream>
#include <vector>

using namespace std;

int N, M, I, W, T;
long A[100001];
int C[100001];
vector<int> V[100001];

void dfs(int idx, int p) {
	for (int i = 0; i < V[idx].size(); i++)
		dfs(V[idx][i], p + C[V[idx][i]]);
	A[idx] += p;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> T;
		if (T != -1)
			V[T].push_back(i);
	}
	for (int i = 0; i < M; i++) {
		cin >> I >> W;
		C[I] += W;
	}
	dfs(1, 0);
	for (int i = 1; i <= N; i++)
		cout << A[i] << ' ';
	cout << '\n';
	return 0;
}