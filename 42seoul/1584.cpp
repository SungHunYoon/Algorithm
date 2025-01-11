#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
using iii = tuple<int, int, int>;

int N, M, X1, Y1, X2, Y2;
int A[501][501];
int D[501][501];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X1 >> Y1 >> X2 >> Y2;
		for (int j = min(X1, X2); j <= max(X1, X2); j++)
			for (int k = min(Y1, Y2); k <= max(Y1, Y2); k++)
				A[j][k] = 1;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> X1 >> Y1 >> X2 >> Y2;
		for (int j = min(X1, X2); j <= max(X1, X2); j++)
			for (int k = min(Y1, Y2); k <= max(Y1, Y2); k++)
				A[j][k] = 2;
	}
	fill(&D[0][0], &D[501][0], 1e9);
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({D[0][0] = 0, 0, 0});
	while (!pq.empty()) {
		auto [d, x, y] = pq.top(); pq.pop();
		if (d > D[x][y]) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 > nx || nx > 500 || 0 > ny || ny > 500) continue;
			if (A[nx][ny] == 2) continue;
			if (d + A[nx][ny] >= D[nx][ny]) continue;
			pq.push({D[nx][ny] = d + A[nx][ny], nx, ny});
		}
	}
	cout << (D[500][500] == 1e9 ? -1 : D[500][500]) << '\n';
	return 0;
}