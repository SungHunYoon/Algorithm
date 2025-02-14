#include <iostream>

using namespace std;

int N, M;
int A[11][100001];
long D[11][100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];
	for (int i = 0; i < M; i++)
		D[i][1] = A[i][1];
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			D[j][i] = D[j][i - 1] + (A[j][i] / 2);
			for (int k = 0; k < M; k++) {
				if (j == k) continue;
				D[j][i] = max(D[j][i], D[k][i - 1] + A[j][i]);
			}
		}
	}
	long answer = 0;
	for (int i = 0; i < M; i++)
		answer = max(answer, D[i][N]);
	cout << answer << '\n';
	return 0;
}