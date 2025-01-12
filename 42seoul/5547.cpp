#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int W, H;
int A[102][102];
bool V[102][102];
bool cV[102][102];
int dx[] = {-1, -1, 1, 1, 0, 0};
int dy[] = {0, 1, 0, 1, -1, 1};

int bfs(int x, int y) {
	int ret = 0;
	queue<ii> q;
	V[x][y] = true;
	q.push({x, y});
	while (!q.empty()) {
		auto [cx, cy] = q.front(); q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (i < 4 && cx % 2 == 0) ny--;
			if (0 > nx || nx > 101 || 0 > ny || ny > 101 || A[nx][ny] != 1) {
				ret++;
				continue;
			}
			if (V[nx][ny]) continue;
			V[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	return ret;
}

int checkBFS(int x, int y) {
	int ret = 0;
	bool flag = true;
	queue<ii> q;
	cV[x][y] = true;
	q.push({x, y});
	while (!q.empty()) {
		auto [cx, cy] = q.front(); q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (i < 4 && cx % 2 == 0) ny--;
			if (0 > nx || nx > 101 || 0 > ny || ny > 101 || A[nx][ny] < 0) {
				flag = false;
				continue;
			}
			if (V[nx][ny]) {
				ret++;
				continue;
			}
			if (cV[nx][ny]) continue;
			cV[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	return (flag ? ret : false);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> W >> H;
	fill(&A[0][0], &A[102][0], -1);
	for (int i = 0; i < H; i++) {
		int offset = (i % 2 == 0 ? 1 : 0);
		for (int j = offset; j < W + offset; j++)
			cin >> A[i][j];
	}
	int answer = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W + 1; j++) {
			if (A[i][j] != 1 || V[i][j]) continue;
			answer += bfs(i, j);
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W + 1; j++) {
			if (A[i][j] != 0 || cV[i][j]) continue;
			answer -= checkBFS(i, j);
		}
	}
	cout << answer << '\n';
	return 0;
}