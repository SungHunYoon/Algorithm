#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using iii = tuple<int, int, int>;

int M, N;
int A[1001][1001];
int D[1001][1001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			D[i][j] = 1e9;
		}
	}
	if (A[1][1] == -1) {
		cout << "-1\n";
		return 0;
	}
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({D[1][1] = A[1][1], 1, 1});
	while (!pq.empty()) {
		auto [d, x, y] = pq.top(); pq.pop();
		if (d > D[x][y]) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 > nx || nx > M || 1 > ny || ny > N) continue;
			if (A[nx][ny] == -1) continue;
			int nd = D[x][y] + A[nx][ny];
			if (nd >= D[nx][ny]) continue;
			pq.push({D[nx][ny] = nd, nx, ny});
		}
	}
	cout << (D[M][N] == 1e9 ? -1 : D[M][N]) << '\n';
	return 0;
}