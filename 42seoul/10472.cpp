#include <iostream>

using namespace std;

int P;
char A[3][3];
char B[3][3];
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

bool checkBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (A[i][j] != B[i][j])
				return false;
		}
	}
	return true;
}

void changeBoard(int idx) {
	int x = idx / 3, y = idx % 3;
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 > nx || nx >= 3 || 0 > ny || ny >= 3)
			continue;
		A[nx][ny] = !A[nx][ny];
	}
}

int dfs(int idx, int cnt) {
	int ret = 1e9;
	if (checkBoard())
		return cnt;
	if (idx >= 9)
		return ret;
	ret = min(ret, dfs(idx + 1, cnt));
	changeBoard(idx);
	ret = min(ret, dfs(idx + 1, cnt + 1));
	changeBoard(idx);
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> P;
	while (P--) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> B[i][j];
				if (B[i][j] == '*')
					B[i][j] = 1;
				else
					B[i][j] = 0;
				A[i][j] = 0;
			}
		}
		cout << dfs(0, 0) << '\n';
	}
	return 0;
}