#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M;
int A[51][51];
bool V[51][51];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

ii bfs(int x, int y) {
	fill(&V[0][0], &V[51][0], false);
	queue<ii> q;
	V[x][y] = true;
	q.push({x, y});
	int ret = 0;
	int cnt = 0;
	while (!q.empty()) {
		ret = 0;
		int len = q.size();
		for (int j = 0; j < len; j++) {
			auto [cx, cy] = q.front(); q.pop();
			ret = max(ret, A[x][y] + A[cx][cy]);
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (1 > nx || nx > N || 1 > ny || ny > M) continue;
				if (A[nx][ny] == 0 || V[nx][ny]) continue;
				V[nx][ny] = true;
				q.push({nx, ny});
			}
		}
		cnt++;
	}
	return {cnt, ret};
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> A[i][j];
	ii answer = {0, 0};
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (A[i][j]) answer = max(answer, bfs(i, j));
		}
	}
	cout << answer.second << '\n';
	return 0;
}