#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int N;
int A[1001][1001];
int D[1001][1001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];
	fill(&D[0][0], &D[1001][0], 1e9);
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({D[1][1] = 0, 1, 1});
	while (!pq.empty()) {
		auto [d, x, y] = pq.top(); pq.pop();
		if (d > D[x][y]) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nd = max(d, abs(A[x][y] - A[nx][ny]));
			if (1 > nx || nx > N || 1 > ny || ny > N) continue;
			if (nd >= D[nx][ny]) continue;
			pq.push({D[nx][ny] = nd, nx, ny});
		}
	}
	cout << D[N][N] << '\n';
	return 0;
}