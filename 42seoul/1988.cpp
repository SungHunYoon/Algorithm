#include <iostream>

using namespace std;

int N, B;
int A[3001];
int D[2][3001][3001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> B;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= min(i, B); j++) {
			D[0][i][j] = max(D[1][i - 1][j - 2], D[0][i - 1][j - 1]) + A[i];
			D[1][i][j] = max(D[0][i][j], D[1][i - 1][j]);
		}
	}
	cout << D[1][N][B] << '\n';
	return 0;
}