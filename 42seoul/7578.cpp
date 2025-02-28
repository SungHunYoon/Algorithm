#include <iostream>

using namespace std;

int N, M;
int A[1000001];
int T[2000000];

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

int query(int s, int e, int rs, int re, int n) {
	if (s > re || e < rs)
		return 0;
	if (rs <= s && e <= re)
		return T[n];
	int mid = (s + e) / 2;
	int ret;
	ret = query(s, mid, rs, re, n * 2);
	ret += query(mid + 1, e, rs, re, n * 2 + 1);
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> M;
		A[M] = i;
	}
	long answer = 0;
	for (int i = 1; i <= N; i++) {
		cin >> M;
		answer += query(1, N, A[M], N, 1);
		update(1, N, A[M], A[M], 1, 1);
	}
	cout << answer << '\n';
	return 0;
}