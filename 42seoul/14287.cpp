#include <iostream>
#include <vector>

using namespace std;

int N, M, seq = 1;
vector<int> V[100001];
int D[100001], I[100001];
long T[400004], L[400004];

int dfs(int idx) {
	I[idx] = seq++;
	D[idx] = 1;
	for (auto v : V[idx]) {
		if (D[v]) continue;
		D[idx] += dfs(v);
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

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		if (a == -1) continue;
		V[a].push_back(i);
	}
	dfs(1);
	while (M--) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			update(1, 1, N, I[b], I[b], c);
		} else {
			cin >> b;
			cout << query(1, 1, N, I[b], I[b] + D[b] - 1) << '\n';
		}
	}
	return 0;
}