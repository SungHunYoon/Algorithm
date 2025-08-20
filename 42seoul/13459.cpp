#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
char A[11][11];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool (*dir[4])(int &, int &, int &, int &);

void printMap() {
	cout << "====================\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << A[i][j];
		}
		cout << '\n';
	}
}

bool up(int &rx, int &ry, int &bx, int &by) {
	int g = 0;
	if (rx < bx) {
		for (int i = rx - 1; i >= 1; i--) {
			if (A[i][ry] == 'O') {
				g |= 1;
				A[i + 1][ry] = '.';
				rx = i;
				break;
			} else if (A[i][ry] != '.') {
				rx = i + 1;
				break;
			}
			swap(A[i][ry], A[i + 1][ry]);
		}
		for (int i = bx - 1; i >= 1; i--) {
			if (A[i][by] == 'O') {
				g |= 2;
				A[i + 1][by] = '.';
				bx = i;
				break;
			} else if (A[i][by] != '.') {
				bx = i + 1;
				break;
			}
			swap(A[i][by], A[i + 1][by]);
		}
	} else {
		for (int i = bx - 1; i >= 1; i--) {
			if (A[i][by] == 'O') {
				g |= 2;
				A[i + 1][by] = '.';
				bx = i;
				break;
			} else if (A[i][by] != '.') {
				bx = i + 1;
				break;
			}
			swap(A[i][by], A[i + 1][by]);
		}
		for (int i = rx - 1; i >= 1; i--) {
			if (A[i][ry] == 'O') {
				g |= 1;
				A[i + 1][ry] = '.';
				rx = i;
				break;
			} else if (A[i][ry] != '.') {
				rx = i + 1;
				break;
			}
			swap(A[i][ry], A[i + 1][ry]);
		}
	}
	return ((g & 3) == 1 ? true : false);
}

bool down(int &rx, int &ry, int &bx, int &by) {
	int g = 0;
	if (rx < bx) {
		for (int i = bx + 1; i <= N; i++) {
			if (A[i][by] == 'O') {
				g |= 2;
				A[i - 1][by] = '.';
				bx = i;
				break;
			} else if (A[i][by] != '.') {
				bx = i - 1;
				break;
			}
			swap(A[i][by], A[i - 1][by]);
		}
		for (int i = rx + 1; i <= N; i++) {
			if (A[i][ry] == 'O') {
				g |= 1;
				A[i - 1][ry] = '.';
				rx = i;
				break;
			} else if (A[i][ry] != '.') {
				rx = i - 1;
				break;
			}
			swap(A[i][ry], A[i - 1][ry]);
		}
	} else {
		for (int i = rx + 1; i <= N; i++) {
			if (A[i][ry] == 'O') {
				g |= 1;
				A[i - 1][ry] = '.';
				rx = i;
				break;
			} else if (A[i][ry] != '.') {
				rx = i - 1;
				break;
			}
			swap(A[i][ry], A[i - 1][ry]);
		}
		for (int i = bx + 1; i <= N; i++) {
			if (A[i][by] == 'O') {
				g |= 2;
				A[i - 1][by] = '.';
				bx = i;
				break;
			} else if (A[i][by] != '.') {
				bx = i - 1;
				break;
			}
			swap(A[i][by], A[i - 1][by]);
		}
	}
	return ((g & 3) == 1 ? true : false);
}

bool left(int &rx, int &ry, int &bx, int &by) {
	int g = 0;
	if (ry < by) {
		for (int i = ry - 1; i >= 1; i--) {
			if (A[rx][i] == 'O') {
				g |= 1;
				A[rx][i + 1] = '.';
				ry = i;
				break;
			} else if (A[rx][i] != '.') {
				ry = i + 1;
				break;
			}
			swap(A[rx][i], A[rx][i + 1]);
		}
		for (int i = by - 1; i >= 1; i--) {
			if (A[bx][i] == 'O') {
				g |= 2;
				A[bx][i + 1] = '.';
				by = i;
				break;
			} else if (A[bx][i] != '.') {
				by = i + 1;
				break;
			}
			swap(A[bx][i], A[bx][i + 1]);
		}
	} else {
		for (int i = by - 1; i >= 1; i--) {
			if (A[bx][i] == 'O') {
				g |= 2;
				A[bx][i + 1] = '.';
				by = i;
				break;
			} else if (A[bx][i] != '.') {
				by = i + 1;
				break;
			}
			swap(A[bx][i], A[bx][i + 1]);
		}
		for (int i = ry - 1; i >= 1; i--) {
			if (A[rx][i] == 'O') {
				g |= 1;
				A[rx][i + 1] = '.';
				ry = i;
				break;
			} else if (A[rx][i] != '.') {
				ry = i + 1;
				break;
			}
			swap(A[rx][i], A[rx][i + 1]);
		}
	}
	return ((g & 3) == 1 ? true : false);
}

bool right(int &rx, int &ry, int &bx, int &by) {
	int g = 0;
	if (ry < by) {
		for (int i = by + 1; i <= M; i++) {
			if (A[bx][i] == 'O') {
				g |= 2;
				A[bx][i - 1] = '.';
				by = i;
				break;
			} else if (A[bx][i] != '.') {
				by = i - 1;
				break;
			}
			swap(A[bx][i], A[bx][i - 1]);
		}
		for (int i = ry + 1; i <= M; i++) {
			if (A[rx][i] == 'O') {
				g |= 1;
				A[rx][i - 1] = '.';
				ry = i;
				break;
			} else if (A[rx][i] != '.') {
				ry = i - 1;
				break;
			}
			swap(A[rx][i], A[rx][i - 1]);
		}
	} else {
		for (int i = ry + 1; i <= M; i++) {
			if (A[rx][i] == 'O') {
				g |= 1;
				A[rx][i - 1] = '.';
				ry = i;
				break;
			} else if (A[rx][i] != '.') {
				ry = i - 1;
				break;
			}
			swap(A[rx][i], A[rx][i - 1]);
		}
		for (int i = by + 1; i <= M; i++) {
			if (A[bx][i] == 'O') {
				g |= 2;
				A[bx][i - 1] = '.';
				by = i;
				break;
			} else if (A[bx][i] != '.') {
				by = i - 1;
				break;
			}
			swap(A[bx][i], A[bx][i - 1]);
		}
	}
	return ((g & 3) == 1 ? true : false);
}

bool dfs(int cnt, int rx, int ry, int bx, int by) {
	if (cnt >= 10) {
		return false;
	}
	char B[11][11];
	int orx = rx, ory = ry, obx = bx, oby = by;
	copy(&A[0][0], &A[11][0], &B[0][0]);
	for (int i = 0; i < 4; i++) {
		if (dir[i](rx, ry, bx, by)) {
			return true;
		}
		if (A[rx][ry] != 'O' && A[bx][by] != 'O' && dfs(cnt + 1, rx, ry, bx, by)) {
			return true;
		}
		copy(&B[0][0], &B[11][0], &A[0][0]);
		rx = orx; ry = ory; bx = obx; by = oby;
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	int rx, ry, bx, by;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
			if (A[i][j] == 'B') {
				bx = i;
				by = j;
			} else if (A[i][j] == 'R') {
				rx = i;
				ry = j;
			}
		}
	}
	dir[0] = up; dir[1] = down; dir[2] = left; dir[3] = right;
	cout << dfs(0, rx, ry, bx, by) << '\n';
	return 0;
}