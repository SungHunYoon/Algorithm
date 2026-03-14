#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
using iiii = tuple<int, int, int, int>;

int N, M, T;
char A[501][501];
int dx[2][4] = { {0, 0}, {-1, 1}, };
int dy[2][4] = { {-1, 1}, {0, 0}, };
int rx[] = {-1, 0, 1, 0};
int ry[] = {0, -1, 0, 1};
int D[4][501][501];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> T;
	priority_queue<iiii, vector<iiii>, greater<iiii>> q;
	fill(&D[0][0][0], &D[4][0][0], 1e9);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
			if ('0' <= A[i][j] && A[i][j] <= '3') {
				q.push({D[A[i][j] - '0'][i][j] = 0, A[i][j] - '0', i, j});
			}
		}
	}
	int answer = 1e9;
	while (!q.empty()) {
		auto [c, d, x, y] = q.top(); q.pop();
		if (c > D[d][x][y]) continue;
		if (A[x][y] == 'S') {
			answer = min(answer, D[d][x][y]);
			continue;
		}
		int rd = (d + 1) % 4;
		if (D[rd][x][y] > D[d][x][y] + T) {
			q.push({D[rd][x][y] = D[d][x][y] + T, rd, x, y});
		}
		for (int i = 0; i < 2; i++) {
			int nd = d;
			int nx = x + dx[nd % 2][i];
			int ny = y + dy[nd % 2][i];
			if (1 > nx || nx > N || 1 > ny || ny > M) continue;
			if (D[nd][nx][ny] <= D[d][x][y] + 1) continue;
			D[nd][nx][ny] = D[d][x][y] + 1;
			bool isValid = true;
			while (A[nx][ny] == 'T') {
				nd = (nd + 1) % 4;
				nx = nx + rx[nd];
				ny = ny + ry[nd];
				if (1 > nx || nx > N || 1 > ny || ny > M || D[nd][nx][ny] <= D[d][x][y] + 1) {
					isValid = false;
					break;
				}
				D[nd][nx][ny] = D[d][x][y] + 1;
			}
			if (isValid) q.push({D[nd][nx][ny], nd, nx, ny});
		}
	}
	cout << (answer == 1e9 ? -1 : answer) << '\n';
	return 0;
}