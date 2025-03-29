#include <iostream>

using namespace std;

int A[1001];
int B[1001];
int D[1001][16][16];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	int len = 1;
	while (cin >> a >> b) {
		A[len] = a;
		B[len] = b;
		len++;
	}
	for (int i = 1; i < len; i++) {
		D[i][1][0] = A[i];
		D[i][0][1] = B[i];
		for (int j = 1; j < i; j++) {
			for (int k = 0; k <= 15; k++) {
				for (int l = 0; l <= 15; l++) {
					if (!D[j][k][l]) continue;
					if (k + 1 <= 15)
						D[i][k + 1][l] = max(D[i][k + 1][l], D[j][k][l] + A[i]);
					if (l + 1 <= 15)
						D[i][k][l + 1] = max(D[i][k][l + 1], D[j][k][l] + B[i]);
				}
			}
		}
	}
	int answer = 0;
	for (int i = 1; i < len; i++) {
		answer = max(answer, D[i][15][15]);
	}
	cout << answer << '\n';
	return 0;
}