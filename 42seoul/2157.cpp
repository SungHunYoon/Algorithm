#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K, A, B, C;
vector<pair<int, int>> V[301];
long dp[301][301];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> A >> B >> C;
		V[A].push_back({B, C});
	}
	for (int i = 0; i < V[1].size(); i++)
		dp[1][V[1][i].first] = max(dp[1][V[1][i].first], (long)V[1][i].second);
	for (int i = 2; i < M; i++) {
		for (int j = 1; j <= N; j++) {
			if (dp[i - 1][j]) {
				for (int k = 0; k < V[j].size(); k++) {
					if (V[j][k].first > j) {
						dp[i][V[j][k].first] = max(dp[i][V[j][k].first], dp[i - 1][j] + V[j][k].second);
					}
				}
			}
		}
	}
	long answer = 0;
	for (int i = 1; i <= M; i++) {
		answer = max(answer, dp[i][N]);
	}
	cout << answer << '\n';
	return 0;
}