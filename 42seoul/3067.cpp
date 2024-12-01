#include <iostream>
#include <algorithm>

using namespace std;

int T, N, M;
int A[21];
int D[21][10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> A[i];
		cin >> M;
		fill(&D[0][0], &D[21][0], 0);
		for (int i = 1; i <= N; i++) {
			D[i][0] = 1;
			for (int j = 1; j <= M; j++) {
				D[i][j] = D[i - 1][j];
				if (j >= A[i])
					D[i][j] += D[i][j - A[i]];
			}
		}
		cout << D[N][M] << '\n';
	}

	return 0;
}