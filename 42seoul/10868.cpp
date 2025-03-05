#include <iostream>

using namespace std;

int N, M;
int A[100001];
int T[400000];

void build(int s, int e, int n) {
	if (s == e) {
		T[n] = A[s];
		return;
	}
	int mid = (s + e) / 2;
	build(s, mid, n * 2);
	build(mid + 1, e, n * 2 + 1);
	T[n] = min(T[n * 2], T[n * 2 + 1]);
}

int query(int s, int e, int rs, int re, int n) {
	if (s > re || e < rs)
		return 1e9;
	if (rs <= s && e <= re)
		return T[n];
	int mid = (s + e) / 2;
	return min(query(s, mid, rs, re, n * 2), query(mid + 1, e, rs, re, n * 2 + 1));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	build(1, N, 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << query(1, N, a, b, 1) << '\n';
	}
	return 0;
}