#include <iostream>
#include <algorithm>

using namespace std;

int M, N;
int A[701][701];
int P[1401];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			A[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		P[a]++;
		P[a + b]++;
	}
	for (int j = 0; j < 2 * M - 1; j++) {
		if (j != 0) P[j] += P[j - 1];
		int x = (M - (j + 1)) > 0 ? (M - (j + 1)) : 0;
		int y = (M - (j + 1)) < 0 ? ((j + 1) - M) : 0; 
		A[x][y] += P[j];
	}
	for (int i = 1; i < M; i++) {
		for (int j = 1; j < M; j++) {
			A[i][j] = max({A[i - 1][j], A[i - 1][j - 1], A[i][j - 1]});
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}