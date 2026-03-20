#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

int T, A, B, N, K;

int powmod(long n, long e) {
	int ret = 1;
	n %= K;
	while (e > 0) {
		if (e & 1) ret = (ret * n) % K;
		n = (n * n) % K;
		e >>= 1;
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> A >> B >> N >> K;
		vector<int> modA(N + 1), modB(N + 1);
		for (int j = 1; j <= N; j++) {
			modA[j] = powmod(j, A);
		}
		for (int j = 1; j <= N; j++) {
			modB[j] = powmod(j, B);
		}
		int answer = 0;
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (j == k) continue;
				if ((modA[j] + modB[k]) % K) continue;
				answer = (answer + 1) % MOD;
			}
		}
		cout << "Case #" << i << ": " << answer << '\n';
	}

	return 0;
}