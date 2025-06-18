#include <iostream>
#include <queue>
#include <tuple>
#include <set>

using namespace std;
using iiii = tuple<int, int, int, int>;
using iii = tuple<int, int, int>;

int R, C, K, W;
int A[21][21];
int B[21][21];
set<iiii> S;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int wx[4][3][3] =
{
	{ {0, 0, 0}, {0, -1, 0}, {0, 1, 0} },
	{ {0, 0, 0}, {0, -1, 0}, {0, 1, 0} },
	{ {0, -1, 0}, {0, 0, -1}, {0, 0, -1} },
	{ {0, 1, 0}, {0, 0, 1}, {0, 0, 1} },
	
};
int wy[4][3][3] =
{
	{ {0, 1, 0}, {0, 0, 1}, {0, 0, 1} },
	{ {0, -1, 0}, {0, 0, -1}, {0, 0, -1} },
	{ {0, 0, 0}, {0, -1, 0}, {0, 1, 0} },
	{ {0, 0, 0}, {0, -1, 0}, {0, 1, 0} },
};

void spreadWind(int x, int y, int t) {
	int V[21][21] = { 0, };
	queue<iii> q;
	V[x][y] = 1;
	q.push({x, y, 5});
	while (!q.empty()) {
		auto [cx, cy, w] = q.front(); q.pop();
		B[cx][cy] += w;
		for (int i = 0; i < 3; i++) {
			int px = cx, py = cy, nx, ny;
			bool flag = true;
			for (int j = 1; j < 3; j++) {
				nx = px + wx[t][i][j];
				ny = py + wy[t][i][j];
				if (1 > nx || nx > R || 1 > ny || ny > C) {
					flag = false;
					break;
				}
				if (S.find({px, py, nx, ny}) != S.end()) {
					flag = false;
					break;
				}
				px = nx;
				py = ny;
			}
			if (flag && !V[nx][ny]) {
				V[nx][ny] = 1;
				if (w - 1 > 0)
					q.push({nx, ny, w - 1});
			}
		}
	}
}

void blowWind() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (A[i][j] && A[i][j] < 5) {
				int type = A[i][j] - 1;
				int nx = i + dx[type];
				int ny = j + dy[type];
				spreadWind(nx, ny, type);
			}
		}
	}
}

void controlTemp() {
	set<iiii> adj;
	int T[21][21] = { 0, };
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (1 > nx || nx > R || 1 > ny || ny > C) continue;
				if (adj.find({i, j, nx, ny}) != adj.end()) continue;
				adj.insert({i, j, nx, ny});
				adj.insert({nx, ny, i, j});
				if (S.find({i, j, nx, ny}) != S.end()) continue;
				int temp = abs(B[i][j] - B[nx][ny]) / 4;
				if (B[i][j] > B[nx][ny]) {
					T[i][j] -= temp;
					T[nx][ny] += temp;
				} else {
					T[i][j] += temp;
					T[nx][ny] -= temp;
				}
			}
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++)
			B[i][j] += T[i][j];
	}
}

void decreaseTemp() {
	B[1][1] = max(0, B[1][1] - 1);
	B[1][C] = max(0, B[1][C] - 1);
	B[R][1] = max(0, B[R][1] - 1);
	B[R][C] = max(0, B[R][C] - 1);
	for (int i = 2; i < R; i++) {
		B[i][1] = max(0, B[i][1] - 1);
		B[i][C] = max(0, B[i][C] - 1);
	}
	for (int i = 2; i < C; i++) {
		B[1][i] = max(0, B[1][i] - 1);
		B[R][i] = max(0, B[R][i] - 1);
	}
}

bool checkTemp() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (A[i][j] != 5) continue;
			if (B[i][j] < K)
				return false;
		}
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C >> K;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++)
			cin >> A[i][j];
	}
	cin >> W;
	for (int i = 0; i < W; i++) {
		int x, y, t;
		cin >> x >> y >> t;
		if (t == 0) {
			S.insert({x, y, x - 1, y});
			S.insert({x - 1, y, x, y});
		} else {
			S.insert({x, y, x, y + 1});
			S.insert({x, y + 1, x, y});
		}
	}
	int answer = 0;
	do {
		blowWind();
		controlTemp();
		decreaseTemp();
		answer++;
	} while (answer <= 100 && !checkTemp());
	cout << answer << '\n';
	return 0;
}