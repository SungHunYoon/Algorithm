#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int N, M;
int A[101][71];
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
bool V[101][71];
priority_queue<iii> pq;

void bfs(int x, int y) {
	queue<ii> q;
	V[y][x] = true;
	q.push({y, x});
	while (!q.empty()) {
		auto [cy, cx] = q.front(); q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (0 > nx || nx >= M || 0 > ny || ny >= N) continue;
			if (V[ny][nx] || !A[ny][nx]) continue;
			if (A[ny][nx] > A[cy][cx]) continue;
			V[ny][nx] = true;
			q.push({ny, nx});
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
			if (A[i][j])
				pq.push({A[i][j], i, j});
		}
	}
	int answer = 0;
	while (!pq.empty()) {
		auto [v, y, x] = pq.top(); pq.pop();
		if (V[y][x]) continue;
		bfs(x, y);
		answer++;
	}
	cout << answer << '\n';
	return 0;
}