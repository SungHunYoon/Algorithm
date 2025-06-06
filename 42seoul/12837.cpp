#include <iostream>

using namespace std;

int N, Q;
long T[4000004];

void update(int n, int s, int e, int idx, int v) {
	if (idx > e || idx < s)
		return;
	if (idx <= s && e <= idx) {
		T[n] += v;
		return;
	}
	int mid = (s + e) / 2;
	update(n * 2, s, mid, idx, v);
	update(n * 2 + 1, mid + 1, e, idx, v);
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

	cin >> N >> Q;
	while (Q--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			update(1, 1, N, b, c);
		else
			cout << query(1, 1, N, b, c) << '\n';
	}

	return 0;
}