#include <iostream>

using namespace std;

long N, MOD = 1e9 + 7;

long DQ(long n) {
	if (n <= 0) {
		return 1;
	}
	if (n == 1) {
		return 2;
	}
	long rVal = DQ(n / 2) % MOD;
	if (n % 2) {
		return rVal * rVal * 2 % MOD;
	}
	return rVal * rVal % MOD;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	cout << DQ(N - 1) << '\n';
	return 0;
}