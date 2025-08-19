#include <iostream>

using namespace std;

#define MOD 1000000007

int N, K;
int A[2001];
int D[2001][2001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	if (K == 1) {
		cout << N << '\n';
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		D[1][i] = 1;
	}
	for (int i = 2; i <= K; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			sum = (sum + D[i - 1][j - 1]) % MOD;
			D[i][j] = sum;
		}
	}
	long curSum = 0;
	for (int i = 1; i <= N; i++) {
		curSum = (curSum + D[K][i]) % MOD;
	}
	long attach = 1;
	for (int i = 0; i < K - 1; i++) {
		attach = (attach * 2) % MOD;
	}
	cout << (curSum * attach) % MOD << '\n';

	return 0;
}
