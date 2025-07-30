#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M, K;
char A[1001];
vector<ii> V[501];
int D[1001][501];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	cin >> M >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		V[a].push_back({c, b});
		V[b].push_back({c, a});
	}
	fill(&D[0][0], &D[1001][0], -1);
	D[0][1] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (auto [c, n] : V[j]) {
				if (D[i - 1][n] == -1) continue;
				D[i][j] = max(D[i][j], D[i - 1][n] + (A[i] == c ? 10 : 0));
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= M; i++) {
		answer = max(answer, D[N][i]);
	}
	cout << answer << '\n';
	return 0;
}