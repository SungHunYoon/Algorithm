#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M, A, B, K, sX, sY, eX, eY;
int map[501][501];
bool V[501][501];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool checkMove(int x, int y, int d) {
	if (d == 1 || d == 3) {
		for (int i = 0; i < A; i++) {
			int nx = x + i;
			int ny = y;
			if (d == 1)
				ny += dy[d];
			else
				ny += dy[d] * B;
			if (1 > nx || nx > N || 1 > ny || ny > M) return false;
			if (map[nx][ny]) return false;
		}
	}
	else {
		for (int i = 0; i < B; i++) {
			int nx = x;
			int ny = y + i;
			if (d == 0)
				nx += dx[d];
			else
				nx += dx[d] * A;
			if (1 > nx || nx > N || 1 > ny || ny > M) return false;
			if (map[nx][ny]) return false;
		}
	}
	return true;
}

int bfs(int x, int y) {
	queue<ii> q;
	V[x][y] = true;
	q.push({x, y});
	int cnt = 0;
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			auto [cx, cy] = q.front(); q.pop();
			if (cx == eX && cy == eY)
				return cnt;
			for (int j = 0; j < 4; j++) {
				int nx = cx + dx[j];
				int ny = cy + dy[j];
				if (V[nx][ny] || !checkMove(cx, cy, j)) continue;
				V[nx][ny] = true;
				q.push({nx, ny});
			}
		}
		cnt++;
	}
	return -1;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> A >> B >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = true;
	}
	cin >> sX >> sY >> eX >> eY;
	cout << bfs(sX, sY) << '\n';
	return 0;
}