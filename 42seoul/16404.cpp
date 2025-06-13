#include <iostream>
#include <vector>

using namespace std;

int N, M, I = 1;
int A[100001];
int B[100001];
vector<int> V[100001];
int D[100001];
long T[400004], L[400004];

int dfs(int idx) {
	if (D[idx]) return D[idx];
	int ret = 0;
	B[idx] = I++;
	for (auto v : V[idx]) {
		ret += dfs(v);
	}
	D[idx] = ret + V[idx].size();
	return D[idx];
}

void propagate(int n, int s, int e) {
	if (L[n]) {
		T[n] += L[n] * (e - s + 1);
		if (s != e) {
			L[n * 2] += L[n];
			L[n * 2 + 1] += L[n];
		}
		L[n] = 0;
	}
}

void update(int n, int s, int e, int l, int r, int v) {
	propagate(n, s, e);
	if (l > e || r < s)
		return;
	if (l <= s && e <= r) {
		L[n] = v;
		propagate(n, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(n * 2, s, mid, l, r, v);
	update(n * 2 + 1, mid + 1, e, l, r, v);
	T[n] = T[n * 2] + T[n * 2 + 1];
}

long query(int n, int s, int e, int l, int r) {
	propagate(n, s, e);
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
		cin >> A[i];
		if (A[i] != -1)
			V[A[i]].push_back(i);
	}
	dfs(1);
	while (M--) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			update(1, 1, N, B[b], B[b] + D[b], c);
		}
		else {
			cin >> b;
			cout << query(1, 1, N, B[b], B[b]) << '\n';
		}
	}
	return 0;
}