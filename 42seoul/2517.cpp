#include <iostream>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N;
ii A[500001];
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
	return query(s, mid, rs, re, n * 2) + query(mid + 1, e, rs, re, n * 2 + 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		A[i] = {n, i};
	}
	sort(A + 1, A + N + 1);
	for (int i = 1; i <= N; i++) {
		A[i].first = i;
		swap(A[i].first, A[i].second);
	}
	sort(A + 1, A + N + 1);
	for (int i = 1; i <= N; i++) {
		cout << i - query(1, N, 1, A[i].second, 1) << '\n';
		update(1, N, A[i].second, A[i].second, 1, 1);
	}

	return 0;
}