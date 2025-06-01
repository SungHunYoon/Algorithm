#include <iostream>

using namespace std;

int N, M;
int T[400004];
int L[400004];

void propagation(int n, int s, int e) {
	if (L[n]) {
		T[n] = abs(T[n] - (e - s + 1));
		if (s != e) {
			L[n * 2] ^= 1;
			L[n * 2 + 1] ^= 1;
		}
		L[n] = 0;
	}
}

void update(int n, int s, int e, int l, int r) {
	propagation(n, s, e);
	if (l > e || r < s)
		return;
	if (l <= s && e <= r) {
		L[n] = 1;
		propagation(n, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(n * 2, s, mid, l, r);
	update(n * 2 + 1, mid + 1, e, l, r);
	T[n] = T[n * 2] + T[n * 2 + 1];
}

int query(int n, int s, int e, int l, int r) {
	propagation(n, s, e);
	if (l > e || r < s)
		return 0;
	if (l <= s && e <= r)
		return T[n];
	int mid = (s + e) / 2;
	int left = query(n * 2, s, mid, l, r);
	int right = query(n * 2 + 1, mid + 1, e, l, r);
	return left + right;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0)
			update(1, 1, N, b, c);
		else
			cout << query(1, 1, N, b, c) << '\n';
	}

	return 0;
}