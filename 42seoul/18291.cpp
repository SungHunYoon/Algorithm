#include <iostream>

using namespace std;

#define MOD 1000000007

long T, N;

long DQ(int n) {
	if (n == 1)
		return 2;
	long ret = DQ(n / 2);
	ret = (ret * ret) % MOD;
	if (n % 2 == 1)
		ret = (ret * 2) % MOD;
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N;
		cout << (N <= 2 ? 1 : DQ(N - 2)) << '\n';
	}
	return 0;
}
