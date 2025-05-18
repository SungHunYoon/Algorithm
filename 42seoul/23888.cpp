#include <iostream>
#include <numeric>

using namespace std;

int A, D, Q;
int64_t T[1000001];
int64_t sumT[4000001];
int64_t gcdT[4000001];

void init(int n, int s, int e, bool f) {
	if (s == e) {
		if (!f) {
			sumT[n] = T[s];
		}
		else
			gcdT[n] = T[s];
		return;
	}
	int mid = (s + e) / 2;
	init(n * 2, s, mid, f);
	init(n * 2 + 1, mid + 1, e, f);
	if (!f)
		sumT[n] = sumT[n * 2] + sumT[n * 2 + 1];
	else
		gcdT[n] = gcd(gcdT[n * 2], gcdT[n * 2 + 1]);
}

int64_t query(int n, int s, int e, int l, int r, bool f) {
	if (l > e || r < s)
		return 0;
	if (l <= s && e <= r)
		return (!f ? sumT[n] : gcdT[n]);
	int mid = (s + e) / 2;
	int64_t left = query(n * 2, s, mid, l, r, f);
	int64_t right = query(n * 2 + 1, mid + 1, e, l, r, f);
	if (!f)
		return left + right;
	else {
		if (l == 0)
			return right;
		if (r == 0)
			return left;
		return gcd(left, right);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> D >> Q;
	for (int64_t i = 1, j = A; i <= 1000000; i++, j += D)
		T[i] = j;
	init(1, 1, 1000000, 0);
	init(1, 1, 1000000, 1);
	for (int i = 0; i < Q; i++) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1)
			cout << query(1, 1, 1000000, l, r, 0) << '\n';
		else
			cout << query(1, 1, 1000000, l, r, 1) << '\n';
	}

	return 0;
}