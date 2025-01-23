#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M;
int A[1001][1001];
bool V[1001][1001];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int x, int y) {
	queue<ii> q;
	V[x][y] = true;
	q.push({x, y});
	while (!q.empty()) {
		auto [cx, cy] = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = (cx + dx[i] + N) % N;
			int ny = (cy + dy[i] + M) % M;
			if (A[nx][ny] || V[nx][ny]) continue;
			V[nx][ny] = true;
			q.push({nx, ny});
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!A[i][j] && !V[i][j]) {
				bfs(i, j);
				answer++;
			}
		}
	}
	cout << answer << '\n';
	return 0;
}