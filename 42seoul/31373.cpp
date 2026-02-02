#include <iostream>

using namespace std;

long N;

long rev(long n) {
	long ret = 0;
	for (long i = 1, j = (1 << 15); i < (1 << 16); i <<= 1, j >>= 1) {
		if (n & i) {
			ret += j;
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	long high = (N & 0xFFFF0000) >> 16;
	long low = (N & 0x0000FFFF);
	cout << min(N, rev(high) + low + 1) << '\n';
	return 0;
}