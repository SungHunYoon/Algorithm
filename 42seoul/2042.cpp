#include <iostream>

using namespace std;

int N, M, K;
long A[1000001];
long T[4000001];

long tree_init(int s, int e, int n) {
	if (s == e)
		return T[n] = A[s];
	int mid = (s + e) / 2;
	T[n] = tree_init(s, mid, n * 2);
	T[n] += tree_init(mid + 1, e, n * 2 + 1);
	return T[n];
}

long tree_update(int s, int e, int rs, int re, int n, long v) {
	if (rs < s || re > e)
		return T[n];
	if (s == e)
		return T[n] = v;
	int mid = (s + e) / 2;
	T[n] = tree_update(s, mid, rs, re, n * 2, v);
	T[n] += tree_update(mid + 1, e, rs, re, n * 2 + 1, v);
	return T[n];
}

long tree_search(int s, int e, int rs, int re, int n) {
	if (re < s || rs > e)
		return 0;
	if (rs <= s && e <= re)
		return T[n];
	int mid = (s + e) / 2;
	long ret = tree_search(s, mid, rs, re, n * 2);
	ret += tree_search(mid + 1, e, rs, re, n * 2 + 1);
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	tree_init(1, N, 1);
	for (int i = 0; i < M + K; i++) {
		long a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			tree_update(1, N, b, b, 1, c);
		else
			cout << tree_search(1, N, b, c, 1) << '\n';
	}
	return 0;
}