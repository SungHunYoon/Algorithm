#include <iostream>

using namespace std;

int K;
bool A[6][6];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool checkMap() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (!A[i][j])
				return false;
		}
	}
	return true;
}

int dfs(int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 == y2) {
		if (checkMap())
			return 1;
		return 0;
	}
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int nx1 = x1 + dx[i];
			int ny1 = y1 + dy[i];
			int nx2 = x2 + dx[j];
			int ny2 = y2 + dy[j];
			if (1 > nx1 || nx1 > 5 || 1 > ny1 || ny1 > 5) continue;
			if (1 > nx2 || nx2 > 5 || 1 > ny2 || ny2 > 5) continue;
			if (A[nx1][ny1] || A[nx2][ny2]) continue;
			A[nx1][ny1] = A[nx2][ny2] = true;
			ret += dfs(nx1, ny1, nx2, ny2);
			A[nx1][ny1] = A[nx2][ny2] = false;
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		A[x][y] = true;
	}
	A[1][1] = A[5][5] = true;
	cout << dfs(1, 1, 5, 5) << '\n';
	return 0;
}