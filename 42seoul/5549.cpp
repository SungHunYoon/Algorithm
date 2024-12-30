#include <iostream>

using namespace std;

int M, N, K;
char A[1001][1001];
int P[3][1001][1001];
int hP[3][1001][1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N >> K;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			for (int k = 0; k < 3; k++)
				P[k][i][j] += P[k][i][j - 1];
			if (A[i][j] == 'J')
				P[0][i][j]++;
			else if (A[i][j] == 'O')
				P[1][i][j]++;
			else
				P[2][i][j]++;
			for (int k = 0; k < 3; k++)
				hP[k][i][j] = hP[k][i - 1][j] + P[k][i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = 0; j < 3; j++)
			cout << hP[j][c][d] - hP[j][c][b - 1] - hP[j][a - 1][d] + hP[j][a - 1][b - 1] << ' ';
		cout << '\n';
	}
	return 0;
}