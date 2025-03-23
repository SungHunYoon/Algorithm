#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, K, R;
int A[101][101];
int E[101][101][4];
bool V[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int x, int y) {
	int ret = 0;
	queue<ii> q;
	V[x][y] = true;
	q.push({x, y});
	while (!q.empty()) {
		auto [cx, cy] = q.front(); q.pop();
		ret += A[cx][cy];
		for (int i = 0; i < 4; i++) {
			if (E[cx][cy][i]) continue;
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (1 > nx || nx > N || 1 > ny || ny > N) continue;
			if (V[nx][ny]) continue;
			V[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K >> R;
	for (int i = 0; i < R; i++) {
		int r[2], c[2];
		cin >> r[0] >> c[0] >> r[1] >> c[1];
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = r[j] + dx[k];
				int ny = c[j] + dy[k];
				if (1 > nx || nx > N || 1 > ny || ny > N) continue;
				if (nx != r[!j] || ny != c[!j]) continue;
				E[r[j]][c[j]][k] = 1; 
			}
		}
	}
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		A[r][c] = 1;
	}
	vector<int> C;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (V[i][j]) continue;
			int cnt = bfs(i, j);
			if (!cnt) continue;
			C.push_back(cnt);
		}
	}
	int answer = 0;
	for (int i = 0; i < C.size(); i++)
		for (int j = i + 1; j < C.size(); j++)
			answer += C[i] * C[j];
	cout << answer << '\n';
	return 0;
}