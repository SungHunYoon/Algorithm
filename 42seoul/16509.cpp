#include <iostream>
#include <algorithm>

using namespace std;

int sX, sY, eX, eY;
int D[10][9];
int dx[8][3] = {
	{-1, -1, -1},
	{-1, -1, -1},
	{1, 1, 1},
	{1, 1, 1},
	{0, -1, -1},
	{0, 1, 1},
	{0, -1, -1},
	{0, 1, 1}
};
int dy[8][3] = {
	{0, -1, -1},
	{0, 1, 1},
	{0, -1, -1},
	{0, 1, 1},
	{-1, -1, -1},
	{-1, -1, -1},
	{1, 1, 1},
	{1, 1, 1}
};
int answer = 1e9;

void dfs(int x, int y, int cnt) {
	D[x][y] = cnt;
	if (x == eX && y == eY)
		return;
	for (int i = 0; i < 8; i++) {
		int nx = x;
		int ny = y;
		for (int j = 0; j < 3; j++) {
			if (nx == eX && ny == eY) {
				nx = -1;
				ny = -1;
				break;
			}
			nx += dx[i][j];
			ny += dy[i][j];
		}
		if (0 > nx || nx > 9 || 0 > ny || ny > 8) continue;
		if (D[nx][ny] <= cnt + 1) continue;
		dfs(nx, ny, cnt + 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> sX >> sY >> eX >> eY;
	fill(&D[0][0], &D[10][0], 1e9);
	dfs(sX, sY, 0);
	cout << D[eX][eY] << '\n';
	return 0;
}