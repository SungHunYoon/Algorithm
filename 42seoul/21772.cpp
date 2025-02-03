#include <iostream>

using namespace std;

int R, C, T;
char A[101][101];
int V[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y, int mov, int cnt) {
	if (mov >= T)
		return cnt;
	int ret = 0;
	V[x][y]++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (1 > nx || nx > R || 1 > ny || ny > C) continue;
		if (A[nx][ny] == '#') continue;
		ret = max(ret, dfs(nx, ny, mov + 1, cnt + (!V[nx][ny] && A[nx][ny] == 'S')));
	}
	V[x][y]--;
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C >> T;
	int sx, sy;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> A[i][j];
			if (A[i][j] == 'G') {
				sx = i;
				sy = j;
			}
		}
	}
	cout << dfs(sx, sy, 0, 0) << '\n';
	return 0;
}