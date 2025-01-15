#include <iostream>

using namespace std;

int N, M;
int A[201][201];
int P[201][201];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
			P[i][j] = P[i][j - 1] + A[i][j];
		}
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			P[i][j] += P[i - 1][j];
	int answer = -1e9;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) { 
			for (int k = 1; k <= N; k++) {
				if (k - i < 0) continue;
				for (int l = 1; l <= M; l++) {
					if (l - j < 0) continue;
					answer = max(answer, P[k][l] - P[k][l - j] - P[k - i][l] + P[k - i][l - j]);
				}
			}
		}
	}
	cout << answer << '\n';
	return 0;
}