#include <iostream>

using namespace std;

#define MOD 1000000007

int N;
long D[3][1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	D[0][1] = 2;
	D[0][2] = 7; D[1][2] = 4; D[2][2] = 3;
	D[0][3] = 22; D[1][3] = 14; D[2][3] = 6;
	for (int i = 4; i <= N; i++) {
		D[1][i] = (D[0][i - 1] * 2) % MOD;
		D[2][i] = (D[1][i - 1] + D[2][i - 1]) % MOD;
		D[0][i] = (D[0][i - 2] + D[1][i] + D[2][i]) % MOD;
	}
	cout << D[0][N] << '\n';
	return 0;
}