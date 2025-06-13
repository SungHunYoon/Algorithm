#include <iostream>

using namespace std;

int N, M;
int A[100001];
int T[400004];

void init(int n, int s, int e) {
	if (s == e) {
		T[n] = s;
		return;
	}
	int mid = (s + e) / 2;
	init(n * 2, s, mid);
	init(n * 2 + 1, mid + 1, e);
	if (A[T[n * 2]] > A[T[n * 2 + 1]])
		T[n] = T[n * 2 + 1];
	else
		T[n] = T[n * 2];
}

void update(int n, int s, int e, int idx, int v) {
	if (idx > e || idx < s)
		return;
	if (idx <= s && e <= idx) {
		A[s] = v;
		return;
	}
	int mid = (s + e) / 2;
	update(n * 2, s, mid, idx, v);
	update(n * 2 + 1, mid + 1, e, idx, v);
	if (A[T[n * 2]] > A[T[n * 2 + 1]])
		T[n] = T[n * 2 + 1];
	else
		T[n] = T[n * 2];
}

int query(int n, int s, int e, int l, int r) {
	if (l > e || r < s)
		return 1e9;
	if (l <= s && e <= r)
		return T[n];
	int mid = (s + e) / 2;
	int lIdx = query(n * 2, s, mid, l, r);
	int rIdx = query(n * 2 + 1, mid + 1, e, l, r);
	if (lIdx == 1e9)
		return rIdx;
	if (rIdx == 1e9)
		return lIdx;
	if (A[lIdx] > A[rIdx])
		return rIdx;
	else
		return lIdx;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	init(1, 1, N);
	cin >> M;
	while (M--) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			update(1, 1, N, b, c);
		} else {
			cout << query(1, 1, N, 1, N) << '\n';
		}
	}

	return 0;
}