#include <iostream>
#include <vector>

using namespace std;

int N, M, seq = 1;
vector<int> V[100001];
int I[100001], D[100001];
long T[2][400004], L[400004];

int dfs(int idx) {
	I[idx] = seq++;
	D[idx] = 1;
	for (auto v : V[idx]) {
		if (D[v]) continue;
		D[idx] += dfs(v);
	}
	return D[idx];
}

void propagate(int n, int s, int e) {
	if (!L[n]) return;
	T[1][n] += L[n] * (e - s + 1);
	if (s != e) {
		L[n * 2] += L[n];
		L[n * 2 + 1] += L[n];
	}
	L[n] = 0;
}

void update(int n, int s, int e, int l, int r, int v, bool t) {
	if (t) propagate(n, s, e);
	if (l > e || r < s)
		return;
	if (l <= s && e <= r) {
		if (t) {
			L[n] = v;
			propagate(n, s, e);
		} else {
			T[t][n] += v;
		}
		return;
	}
	int mid = (s + e) / 2;
	update(n * 2, s, mid, l, r, v, t);
	update(n * 2 + 1, mid + 1, e, l, r, v, t);
	T[t][n] = T[t][n * 2] + T[t][n * 2 + 1];
}

long query(int n, int s, int e, int l, int r, int t) {
	if (t) propagate(n, s, e);
	if (l > e || r < s)
		return 0;
	if (l <= s && e <= r)
		return T[t][n];
	int mid = (s + e) / 2;
	long left = query(n * 2, s, mid, l, r, t);
	long right = query(n * 2 + 1, mid + 1, e, l, r, t);
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
	bool type = true;
	while (M--) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			if (type)
				update(1, 1, N, I[b], I[b] + D[b] - 1, c, type);
			else
				update(1, 1, N, I[b], I[b], c, type);
		} else if (a == 2) {
			cin >> b;
			cout << query(1, 1, N, I[b], I[b] + D[b] - 1, false) + query(1, 1, N, I[b], I[b], true) << '\n';
		} else {
			type = !type;
		}
	}

	return 0;
}