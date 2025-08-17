#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
using iiiiii = tuple<int, int, int, int, int, int>;

int N, H, D;
char A[501][501];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int M[11][501][501];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> H >> D;
	queue<iiiiii> q;
	int idx = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			if (A[i][j] == 'S') {
				M[0][i][j] = true;
				q.push({0, H, 0, 0, i, j});
			} else if (A[i][j] == 'U') {
				A[i][j] = idx++;
			}
		}
	}
	int answer = 1e9;
	while (!q.empty()) {
		auto [t, h, d, u, x, y] = q.front(); q.pop();
		if (A[x][y] == 'E') {
			answer = min(answer, t);
			break;
		}
		if (h == 0) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nh = h, nd = d, nu = u, nt = t + 1;
			if (1 > nx || nx > N || 1 > ny || ny > N) continue;
			if (1 <= A[nx][ny] && A[nx][ny] <= 10) {
				nu = A[nx][ny];
				nd = D;
			}
			if (nd > 0) nd--;
			else if (nh > 0) nh--;
			if (M[nu][nx][ny]) continue;
			M[nu][nx][ny] = true;
			q.push({nt, nh, nd, nu, nx, ny});
		}
	}
	cout << (answer == 1e9 ? -1 : answer) << '\n';
	return 0;
}