#include <iostream>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, Q;
ii A[301];
int D[301][301];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i].first >> A[i].second;
	}
	fill(&D[0][0], &D[301][0], 1e9);
	for (int i = 1; i <= N; i++) {
		D[i][i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if ((A[i].first <= A[j].first && A[j].first <= A[i].second) ||
				(A[i].first <= A[j].second && A[j].second <= A[i].second)) {
				D[i][j] = D[j][i] = 1;
			}
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	cin >> Q;
	while (Q--) {
		int a, b;
		cin >> a >> b;
		cout << (D[a][b] == 1e9 ? -1 : D[a][b]) << '\n';
	}

	return 0;
}