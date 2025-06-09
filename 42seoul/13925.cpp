#include <iostream>

using namespace std;

#define MOD 1000000007

int N, M;
int A[100001];
long T[400004];
long L[2][400004];

void init(int n, int s, int e) {
	if (s == e) {
		T[n] = A[s];
		return;
	}
	int mid = (s + e) / 2;
	init(n * 2, s, mid);
	init(n * 2 + 1, mid + 1, e);
	T[n] = (T[n * 2] + T[n * 2 + 1]) % MOD;
}

void propagate(int n, int s, int e) {
	if (L[0][n] == 1 && L[1][n] == 0) return;
	T[n] = (((L[0][n] * T[n]) % MOD) + (((e - s + 1) * L[1][n]) % MOD)) % MOD;
	if (s != e) {
		L[0][n * 2] = (L[0][n * 2] * L[0][n]) % MOD;
		L[1][n * 2] = (L[1][n * 2] * L[0][n]) % MOD;
		L[1][n * 2] = (L[1][n * 2] + L[1][n]) % MOD;
		L[0][n * 2 + 1] = (L[0][n * 2 + 1] * L[0][n]) % MOD;
		L[1][n * 2 + 1] = (L[1][n * 2 + 1] * L[0][n]) % MOD;
		L[1][n * 2 + 1] = (L[1][n * 2 + 1] + L[1][n]) % MOD;
	}
	L[0][n] = 1;
	L[1][n] = 0;
}

void update(int n, int s, int e, int l, int r, int v, int t) {
	propagate(n, s, e);
	if (l > e || r < s)
		return;
	if (l <= s && e <= r) {
		if (t == 1) {
			L[0][n] = 1;
			L[1][n] = v;
		} else if (t == 2) {
			L[0][n] = v;
		} else {
			L[0][n] = 0;
			L[1][n] = v;
		}
		propagate(n, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(n * 2, s, mid, l, r, v, t);
	update(n * 2 + 1, mid + 1, e, l, r, v, t);
	T[n] = (T[n * 2] + T[n * 2 + 1]) % MOD;
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
	return (left + right) % MOD;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	init(1, 1, N);
	for (int i = 1; i <= 4 * N; i++)
		L[0][i] = 1;
	cin >> M;
	while (M--) {
		int a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update(1, 1, N, b, c, d, 1);
		} else if (a == 2) {
			cin >> b >> c >> d;
			update(1, 1, N, b, c, d, 2);
		} else if (a == 3) {
			cin >> b >> c >> d;
			update(1, 1, N, b, c, d, 3);
		} else {
			cin >> b >> c;
			cout << query(1, 1, N, b, c) << '\n';
		}
	}
	return 0;
}