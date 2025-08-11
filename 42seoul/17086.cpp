#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int N, M;
int A[51][51];
int D[51][51];
bool V[51][51];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void bfs(int x, int y, int idx) {
	queue<iii> q;
	D[x][y] = 0;
	V[x][y] = idx;
	q.push({x, y, 0});
	while (!q.empty()) {
		auto [cx, cy, cost] = q.front(); q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (1 > nx || nx > N || 1 > ny || ny > M) continue;
			if (V[nx][ny] == idx || cost + 1 >= D[nx][ny]) continue;
			V[nx][ny] = idx;
			D[nx][ny] = cost + 1;
			q.push({nx, ny, cost + 1});
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
			D[i][j] = 1e9;
		}
	}
	int idx = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (A[i][j]) {
				bfs(i, j, idx++);
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			answer = max(answer, D[i][j]);
		}
	}
	cout << answer << '\n';
	return 0;
}