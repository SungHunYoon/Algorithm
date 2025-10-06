#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M;
vector<ii> V[101][101];
bool light[101][101];
bool visit[101][101];
bool nextQ[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		V[x][y].push_back({a, b});
	}
	queue<ii> q;
	light[1][1] = visit[1][1] = true;
	q.push({1, 1});
	while (!q.empty()) {
		while (!q.empty()) {
			auto [x, y] = q.front(); q.pop();
			for (auto [a, b] : V[x][y]) {
				light[a][b] = true;
				if (nextQ[a][b] && !visit[a][b]) {
					visit[a][b] = true;
					q.push({a, b});
				}
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (1 > nx || nx > N || 1 > ny || ny > N) continue;
				if (visit[nx][ny]) continue;
				if (!light[nx][ny]) {
					nextQ[nx][ny] = true;
					continue;
				}
				visit[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
	cout << count(&light[0][0], &light[N + 1][0], true) << '\n';

	return 0;
}