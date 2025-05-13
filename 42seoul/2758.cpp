#include <iostream>
#include <vector>

using namespace std;

int T, N, M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N >> M;
		vector<vector<long>> D(N + 1, vector<long>(M + 1));
		for (int i = 1; i <= M; i++)
			D[1][i] = 1;
		for (int i = 2; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				for (int k = j * 2; k <= M; k++) {
					D[i][k] += D[i - 1][j];
				}
			}
		}
		long answer = 0;
		for (int i = 1; i <= M; i++)
			answer += D[N][i];
		cout << answer << '\n';
	}
	return 0;
}