#include <iostream>

using namespace std;

#define MOD 1000000000

int N; 
int D[101][1 << 10][10];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i < 10; i++)
		D[1][1 << i][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < (1 << 10); j++) {
			for (int k = 0; k < 10; k++) {
				if (k != 0) {
					int &V = D[i][j | (1 << (k - 1))][k - 1];
					V = (V + D[i - 1][j][k]) % MOD;
				}
				if (k != 9) {
					int &V = D[i][j | (1 << (k + 1))][k + 1];
					V = (V + D[i - 1][j][k]) % MOD;
				}
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 10; i++)
		answer = (answer + D[N][(1 << 10) - 1][i]) % MOD;
	cout << answer << '\n';
	return 0;
}