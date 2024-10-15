#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[16][16];
int D[16][65536];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			if (A[i][j] == 0)
				A[i][j] = 1e9;
		}
	}
	for (int i = 0; i < N; i++)
		fill(D[i], D[i] + 65536, 1e9);
	D[0][1] = 0;
	for (int k = 0; k < (1 << N); k++) {
		for (int i = 0; i < N; i++) {
			if (!(k & (1 << i))) continue;
			for (int j = 0; j < N; j++) {
				if (k & (1 << j)) continue;
				D[j][k | (1 << j)] = min(D[j][k | (1 << j)], D[i][k] + A[i][j]);
			}
		}
	}
	int answer = 1e9;
	for (int i = 0; i < N; i++) {
		answer = min(answer, D[i][(1 << N) - 1] + A[i][0]);
	}
	cout << answer << '\n';
	// for (int i = 0; i < N; i++) {
	// 	for (int j = 0; j < (1 << N); j++)
	// 		cout << D[i][j] << ' ';
	// 	cout << '\n';
	// }
	return 0;
}
