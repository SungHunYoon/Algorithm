#include <iostream>
#include <vector>

using namespace std;

int N, M;
int A[5001];
vector<int> V[5001];
int D[5001];

int dfs(int idx) {
	if (D[idx])
		return D[idx];
	int ret = 0;
	for (auto v : V[idx]) {
		if (A[v] > A[idx])
			ret = max(ret, dfs(v));
	}
	return D[idx] = ret + 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		dfs(i);
		cout << D[i] << '\n';
	}
	return 0;
}