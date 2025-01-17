#include <iostream>

using namespace std;

int M, N;
int A[1001][1001];
int D[1001][1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N;
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];
	int answer = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i][j] > 0) continue;
			D[i][j] = min(D[i - 1][j - 1], min(D[i - 1][j], D[i][j - 1])) + 1;
			answer = max(answer, D[i][j]);
		}
	}
	cout << answer << '\n';
	return 0;
}