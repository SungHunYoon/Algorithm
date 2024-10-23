#include <iostream>

using namespace std;

int N;
int A[34][34];
long D[3][34][34];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];
	D[0][1][2] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (D[0][i][j] != 1e9) {
				if (!A[i][j + 1])
					D[0][i][j + 1] += D[0][i][j];
				if (!A[i + 1][j + 1] && !A[i][j + 1] && !A[i + 1][j])
					D[2][i + 1][j + 1] += D[0][i][j];
			}
			if (D[1][i][j] != 1e9) {
				if (!A[i + 1][j])
					D[1][i + 1][j] += D[1][i][j];
				if (!A[i + 1][j + 1] && !A[i][j + 1] && !A[i + 1][j])
					D[2][i + 1][j + 1] += D[1][i][j];
			}
			if (D[2][i][j] != 1e9) {
				if (!A[i][j + 1])
					D[0][i][j + 1] += D[2][i][j];
				if (!A[i + 1][j])
					D[1][i + 1][j] += D[2][i][j];
				if (!A[i + 1][j + 1] && !A[i][j + 1] && !A[i + 1][j])
					D[2][i + 1][j + 1] += D[2][i][j];
			}
		}
	}
	long answer = 0;
	for (int k = 0; k < 3; k++) {
		if (D[k][N][N] != 1e9)
			answer += D[k][N][N];
	}
	cout << answer << '\n';
	return 0;
}