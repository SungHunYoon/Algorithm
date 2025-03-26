#include <iostream>

using namespace std;

int N, M, C;
char A[31][31];
bool V[31][31];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool checkPossible(int x, int y) {
	if (1 > x || x > N || 1 > y || y > M)
		return false;
	if (A[x][y] == '*')
		return false;
	if (V[x][y])
		return false;
	return true;
}

int dfs(int x, int y, int d, int c, int a) {
	int ret = (c == C ? a : 1e9);
	V[x][y] = true;
	int nx = x + dx[d];
	int ny = y + dy[d];
	if (d == -1 || !checkPossible(nx, ny)) {
		for (int i = 0; i < 4; i++) {
			if (i == d) continue;
			nx = x + dx[i];
			ny = y + dy[i];
			if (!checkPossible(nx, ny)) continue;
			if (V[nx][ny]) continue;
			ret = min(ret, dfs(nx, ny, i, c + 1, a + 1));
		}
	} else {
		ret = min(ret, dfs(nx, ny, d, c + 1, a));
	}
	V[x][y] = false;
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 1;
	while (cin >> N >> M) {
		C = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> A[i][j];
				if (A[i][j] == '.')
					C++;
			}
		}
		int answer = 1e9;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (A[i][j] == '*') continue;
				answer = min(answer, dfs(i, j, -1, 1, 0));
			}
		}
		cout << "Case " << T << ": ";
		cout << (answer == 1e9 ? -1 : answer) << '\n';
		T++;
	}
	return 0;
}