#include <iostream>
#include <vector>

using namespace std;

int N, C, Q, seq = 1;
vector<int> V[200001];
int D[200001], I[200001], L[200001];
long T[800004];

int dfs(int idx, int level) {
	I[idx] = seq++;
	D[idx] = 1;
	L[idx] = level;
	for (auto v : V[idx]) {
		if (D[v]) continue;
		D[idx] += dfs(v, level + 1);
	}
	return D[idx];
}

void update(int n, int s, int e, int l, int r, int v) {
	if (l > e || r < s)
		return;
	if (l <= s && e <= r) {
		T[n] += v;
		return;
	}
	int mid = (s + e) / 2;
	update(n * 2, s, mid, l, r, v);
	update(n * 2 + 1, mid + 1, e, l, r, v);
	T[n] = T[n * 2] + T[n * 2 + 1];
}

long query(int n, int s, int e, int l, int r) {
	if (l > e || r < s)
		return 0;
	if (l <= s && e <= r)
		return T[n];
	int mid = (s + e) / 2;
	long left = query(n * 2, s, mid, l, r);
	long right = query(n * 2 + 1, mid + 1, e, l, r);
	return left + right;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> C;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(C, 1);
	cin >> Q;
	while (Q--) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			update(1, 1, N, I[b], I[b], 1);
		} else {
			cout << query(1, 1, N, I[b], I[b] + D[b] - 1) * L[b] << '\n';
		}
	}
	return 0;
}