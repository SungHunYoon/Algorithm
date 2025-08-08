#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M, Q;
int A[501][501];
int D[501];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		A[a][b] = A[b][a] = 1;
	}
	cin >> Q;
	while (Q--) {
		int a, b, c;
		cin >> a >> b >> c;
		A[b][c] = A[c][b] = (a == 1 ? 1 : 0);
		fill(D + 1, D + N + 1, 1e9);
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		pq.push({D[1] = 0, 1});
		while (!pq.empty()) {
			auto [d, n] = pq.top(); pq.pop();
			if (d > D[n]) continue;
			for (int i = 1; i <= N; i++) {
				if (!A[n][i]) continue;
				if (d + 1 >= D[i]) continue;
				pq.push({D[i] = d + 1, i});
			}
		}
		for (int i = 1; i <= N; i++) {
			cout << (D[i] == 1e9 ? -1 : D[i]) << ' ';
		}
		cout << '\n';
	}

	return 0;
}