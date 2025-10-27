#include <iostream>

using namespace std;

int N, K;

long cntFactor(long mid) {
	long ret = 0;
	for (int i = 1; i <= N; i++) {
		ret += min((long)N, mid / i);
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	long s = 1, e = min((long)1e9, (long)N * N);
	long answer = 0;
	while (s <= e) {
		long mid = (s + e) / 2;
		if (cntFactor(mid) >= K) {
			answer = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	cout << answer << '\n';
	return 0;
}