#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[10001];
int D[502][10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	D[1][1] = A[1];
	for (int i = 2; i <= N; i++) {
		D[0][i] = D[0][i - 1];
		for (int j = 1; j <= min(M, i); j++)
			D[0][i] = max(D[0][i], D[j][i - j]);
		for (int j = 1; j <= M; j++)
			D[j][i] = D[j - 1][i - 1] + A[i];
	}
	cout << D[0][N] << '\n';
	return 0;
}