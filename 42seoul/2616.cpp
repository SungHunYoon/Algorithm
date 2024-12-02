#include <iostream>

using namespace std;

int N, M;
int A[50001];
int P[50001];
int D[3][50001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	cin >> M;
	for (int i = 1; i <= N; i++)
		P[i] = P[i - 1] + A[i];
	for (int i = M; i <= N; i++)
		D[0][i] = max(D[0][i - 1], P[i] - P[i - M]);
	for (int i = 1; i < 3; i++)
		for (int j = M; j <= N; j++)
			D[i][j] = max(D[i][j - 1], D[i - 1][j - M] + P[j] - P[j - M]);
	cout << D[2][N] << '\n';
	return 0;
}