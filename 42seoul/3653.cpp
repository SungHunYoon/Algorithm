#include <iostream>
#include <algorithm>

using namespace std;

int T, N, M;
int S[800001], I[100001];

void update(int s, int e, int rs, int re, int n, int v) {
	if (s > re || e < re)
		return;
	if (rs <= s && e <= re) {
		S[n] += v;
		return;
	}
	int mid = (s + e) / 2;
	update(s, mid, rs, re, n * 2, v);
	update(mid + 1, e, rs, re, n * 2 + 1, v);
	S[n] = S[n * 2] + S[n * 2 + 1];
}

int query(int s, int e, int rs, int re, int n) {
	if (s > re || e < rs)
		return 0;
	if (rs <= s && e <= re)
		return S[n];
	int mid = (s + e) / 2;
	return query(s, mid, rs, re, n * 2) + query(mid + 1, e, rs, re, n * 2 + 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N >> M;
		fill(S, S + (N + M) * 4, 0);
		for (int i = 1; i <= N; i++) {
			I[i] = N - i + 1;
			update(1, N + M, I[i], I[i], 1, 1);
		}
		int cnt = N;
		for (int i = 1; i <= M; i++) {
			int n;
			cin >> n;
			cout << query(1, N + M, I[n] + 1, cnt, 1) << ' ';
			update(1, N + M, I[n], I[n], 1, -1);
			I[n] = ++cnt;
			update(1, N + M, I[n], I[n], 1, 1);
		}
		cout << '\n';
	}
	return 0;
}