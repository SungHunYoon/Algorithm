#include <iostream>
#include <algorithm>

using namespace std;

int N, Q;
int A[100001];
long T[400004];

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

void update(int n, int s, int e, int idx, int v) {
	if (idx < s || idx > e)
		return;
	if (idx <= s && e <= idx) {
		T[n] = v;
		return;
	}
	int mid = (s + e) / 2;
	update(n * 2, s, mid, idx, v);
	update(n * 2 + 1, mid + 1, e, idx, v);
	T[n] = T[n * 2] + T[n * 2 + 1];
}

long query(int n, int s, int e, int l, int r){
	if (r < s || l > e)
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
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	init(1, 1, N);
	for (int i = 0; i < Q; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);
		cout << query(1, 1, N, x, y) << '\n';
		update(1, 1, N, a, b);
	}

	return 0;
}