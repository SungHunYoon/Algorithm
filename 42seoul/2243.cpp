#include <iostream>

using namespace std;

int N, A, B, C;
int T[4000000];

void update(int s, int e, int rs, int re, int n, int v) {
	if (s > re || e < rs)
		return;
	if (rs <= s && e <= re) {
		T[n] += v;
		return;
	}
	int mid = (s + e) / 2;
	update(s, mid, rs, re, n * 2, v);
	update(mid + 1, e, rs, re, n * 2 + 1, v);
	T[n] = T[n * 2] + T[n * 2 + 1];
}

int query(int s, int e, int n, int v) {
	if (s == e)
		return s;
	int mid = (s + e) / 2;
	if (T[n * 2] >= v)
		return query(s, mid, n * 2, v);
	else
		return query(mid + 1, e, n * 2 + 1, v - T[n * 2]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A;
		if (A == 1) {
			cin >> B;
			int rank = query(1, 1000000, 1, B);
			cout << rank << '\n';
			update(1, 1000000, rank, rank, 1, -1);
		} else {
			cin >> B >> C;
			update(1, 1000000, B, B, 1, C);
		}
	}

	return 0;
}