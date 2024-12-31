#include <iostream>

using namespace std;

long N, X, M;
long D[51];

long DQ(long start, long range, long n, long s) {
	if (s > start + range - 1)
		return 0;
	if (n == 0)
		return 1;
	long ret = start + range / 2 >= s ? 1 : 0;
	long pRange = (range - 3) / 2;
	if (s <= start && start + pRange >= s)
		ret += D[n] * 2;
	else {
		ret += DQ(start + 1, pRange, n - 1, s);
		ret += DQ(start + 2 + pRange, pRange, n - 1, s);
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> X;
	M = 1;
	D[1] = 1;
	for (int i = 1; i <= N; i++) {
		M = M * 2 + 3;
		D[i] = D[i - 1] * 2 + 1;
	}
	cout << DQ(1, M, N, M - X + 1) << '\n';
	return 0;
}