#include <iostream>

using namespace std;

int N, Q;
long A[100001], T[400004], I[400001], L[400004];

void init(int n, int s, int e) {
	if (s == e) {
		T[n] = A[s];
		return;
	}
	int mid = (s + e) / 2;
	init(n * 2, s, mid);
	init(n * 2 + 1, mid + 1, e);
	T[n] = T[n * 2] + T[n * 2 + 1];
}

void propagate(int n, int s, int e) {
	if (L[n]) {
		int cnt = (e - s + 1);
		T[n] += ((L[n] + (L[n] + I[n] * (cnt - 1))) * cnt) / 2;
		if (s != e) {
			I[n * 2] += I[n];
			I[n * 2 + 1] += I[n];
			L[n * 2] += L[n];
			L[n * 2 + 1] += L[n] + I[n] * ((s + e) / 2 - s + 1);
		}
		I[n] = L[n] = 0;
	}
}

void update(int n, int s, int e, int l, int r, int v) {
	propagate(n, s, e);
	if (l > e || r < s)
		return;
	if (l <= s && e <= r) {
		L[n] = v + (s - l);
		I[n] = 1;
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

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	init(1, 1, N);
	cin >> Q;
	while (Q--) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			update(1, 1, N, b, c, 1);
		} else {
			cin >> b;
			cout << query(1, 1, N, b, b) << '\n';
		}
	}

	return 0;
}