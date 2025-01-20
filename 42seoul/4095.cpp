#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[1001][1001];
int D[1001][1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> N >> M) {
		if (N == 0 && M == 0) break;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> A[i][j];
				D[i][j] = 0;
			}
		}
		int answer = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!A[i][j]) continue;
				D[i][j] = min({D[i - 1][j], D[i][j - 1], D[i - 1][j - 1]}) + 1;
				answer = max(answer, D[i][j]);
			}
		}
		cout << answer << '\n';
	}

	return 0;
}