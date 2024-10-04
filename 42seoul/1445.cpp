#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M;
char A[51][51];
ii V[51][51];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	queue<ii> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
			V[i][j] = {1e9, 1e9};
			if (A[i][j] == 'S') {
				q.push({i, j});
				V[i][j] = {0, 0};
			}
		}
	}
	ii answer = { 1e9, 1e9 };
	while (!q.empty()) {
		auto [y, x] = q.front(); q.pop();

		if (A[y][x] == 'F') {
			answer = min(answer, V[y][x]);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 > nx || nx >= M || 0 > ny || ny >= N) continue;
			int c = 0;
			int g = 0;
			if (A[ny][nx] == 'g')
				c = 1;
			else if (A[ny][nx] == '.') {
				for (int j = 0; j < 4; j++) {
					int tx = nx + dx[j];
					int ty = ny + dy[j];
					if (0 > tx || tx >= M || 0 > ty || ty >= N) continue;
					if (A[ty][tx] == 'g')
						g = 1;
				}
			}
			int nc = V[y][x].first + c;
			int ng = V[y][x].second + g;
			if (nc < V[ny][nx].first) {
				V[ny][nx] = {nc, ng};
				q.push({ny, nx});
			} else if (nc == V[ny][nx].first) {
				if (ng < V[ny][nx].second) {
					V[ny][nx] = {nc, ng};
					q.push({ny, nx});
				}
			}
		}
	}
	// for (int i = 0; i < N; i++) {
	// 	for (int j = 0; j < M; j++)
	// 		cout << "[" << V[i][j].first << "," << V[i][j].second << "] ";
	// 	cout << '\n';
	// }
	cout << answer.first << " " << answer.second << '\n';
	return 0;
}