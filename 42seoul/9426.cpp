#include <iostream>

using namespace std;

int N, K;
int A[250001];
int T[65536 * 4];

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

int query(int s, int e, int n, int k) {
	if (s == e)
		return s;
	int mid = (s + e) / 2;
	if (T[n * 2] >= k)
		return query(s, mid, n * 2, k);
	else 
		return query(mid + 1, e, n * 2 + 1, k - T[n * 2]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	for (int i = 1; i < K; i++)
		update(0, 65535, A[i], A[i], 1, 1);
	long answer = 0;
	int mid = (K + 1) / 2;
	for (int i = K; i <= N; i++) {
		update(0, 65535, A[i], A[i], 1, 1);
		answer += query(0, 65535, 1, mid);
		update(0, 65535, A[i - K + 1], A[i - K + 1], 1, -1);
	}
	cout << answer << '\n';
	return 0;
}