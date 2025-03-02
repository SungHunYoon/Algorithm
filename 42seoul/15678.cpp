#include <iostream>

using namespace std;

int N, D;
int A[100001];
long T[400000];

void update(int s, int e, int rs, int re, int n, long v) {
	if (s > re || e < rs)
		return;
	if (rs <= s && e <= re) {
		T[n] = max(T[n], v);
		return;
	}
	int mid = (s + e) / 2;
	update(s, mid, rs, re, n * 2, v);
	update(mid + 1, e, rs, re, n * 2 + 1, v);
	T[n] = max(T[n * 2], T[n * 2 + 1]);
}

long query(int s, int e, int rs, int re, int n) {
	if (s > re || e < rs)
		return -1e9;
	if (rs <= s && e <= re)
		return T[n];
	int mid = (s + e) / 2;
	return max(query(s, mid, rs, re, n * 2), query(mid + 1, e, rs, re, n * 2 + 1)); 
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> D;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	update(1, N, 1, 1, 1, A[1]);
	long answer = A[1];
	for (int i = 2; i <= N; i++) {
		long q = query(1, N, max(1, i - D), i - 1, 1);
		long uValue = q + A[i];
		answer = max(answer, uValue);
		update(1, N, i, i, 1, uValue);
	}
	cout << answer << '\n';
	return 0;
}