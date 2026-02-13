#include <iostream>

using namespace std;

long long T, K;
long long D[64];

int DQ(int n, bool flip) {
	long long mid = D[n] / 2 + 1;
	if (K == mid) {
		return flip ? 1 : 0;
	}
	if (K > mid) {
		K = D[n] - K + 1;
		flip = !flip;
	}
	return DQ(n - 1, flip);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	D[1] = 1;
	for (int i = 2; i <= 63; i++) {
		D[i] = D[i - 1] * 2 + 1;
	}
	for (int i = 1; i <= T; i++) {
		cin >> K;
		int n = 0;
		for (int j = 1; j <= 63; j++) {
			if (D[j] >= K) {
				n = j;
				break;
			}
		}
		cout << "Case #" << i << ": " << DQ(n, false) << '\n';
	}

	return 0;
}