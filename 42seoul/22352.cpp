#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M, T;
int A[31][31];
int B[31][31];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y, int idx) {
	queue<ii> q;
	int org = A[x][y];
	A[x][y] = idx;
	q.push({x, y});
	while (!q.empty()) {
		auto [cx, cy] = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
			if (org != A[nx][ny]) continue;
			A[nx][ny] = idx;
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
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> B[i][j];
	int diff = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) {
				diff++;
				bfs(i, j, B[i][j]);
			}
		}
	}
	bool flag = true;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (A[i][j] != B[i][j])
				flag = false;
	if (diff < 2 && flag) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}