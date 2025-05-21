#include <iostream>

using namespace std;

#define MOD 10000

int N, K;
int A[101];
int D[101][2][4];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		int a, b;
		cin >> a >> b;
		A[a] = b;
	}
	if (A[1])
		D[1][0][A[1]] = 1;
	else
		D[1][0][1] = D[1][0][2] = D[1][0][3] = 1;
	for (int i = 2; i <= N; i++) {
		if (A[i] == 1) {
			D[i][0][1] = (D[i - 1][0][2] + D[i - 1][0][3] + D[i - 1][1][2] + D[i - 1][1][3]) % MOD;
			D[i][1][1] = D[i - 1][0][1];
		}
		else if (A[i] == 2) {
			D[i][0][2] = (D[i - 1][0][1] + D[i - 1][0][3] + D[i - 1][1][1] + D[i - 1][1][3]) % MOD;
			D[i][1][2] = D[i - 1][0][2];
		}
		else if (A[i] == 3) {
			D[i][0][3] = (D[i - 1][0][1] + D[i - 1][0][2] + D[i - 1][1][1] + D[i - 1][1][2]) % MOD;
			D[i][1][3] = D[i - 1][0][3];
		}
		else {
			D[i][0][1] = (D[i - 1][0][2] + D[i - 1][0][3] + D[i - 1][1][2] + D[i - 1][1][3]) % MOD;
			D[i][1][1] = D[i - 1][0][1];
			D[i][0][2] = (D[i - 1][0][1] + D[i - 1][0][3] + D[i - 1][1][1] + D[i - 1][1][3]) % MOD;
			D[i][1][2] = D[i - 1][0][2];
			D[i][0][3] = (D[i - 1][0][1] + D[i - 1][0][2] + D[i - 1][1][1] + D[i - 1][1][2]) % MOD;
			D[i][1][3] = D[i - 1][0][3];
		}
	}
	int answer = 0;
	for (int i = 1; i <= 3; i++)
		answer = (answer + D[N][0][i] + D[N][1][i]) % MOD;
	cout << answer << '\n';
	return 0;
}