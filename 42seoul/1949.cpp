#include <iostream>
#include <vector>

using namespace std;

int N;
int A[10001];
int D[2][10001];
bool visit[10001];
vector<int> V[10001];

void dfs(int idx) {
	int ret = 0;
	visit[idx] = true;
	for (int i = 0; i < V[idx].size(); i++) {
		if (!visit[V[idx][i]]) {
			dfs(V[idx][i]);
			D[0][idx] += D[1][V[idx][i]];
			D[1][idx] += max(D[0][V[idx][i]], D[1][V[idx][i]]);
		}
	}
	D[0][idx] += A[idx];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1);
	cout << max(D[0][1], D[1][1]) << '\n';
	return 0;
}