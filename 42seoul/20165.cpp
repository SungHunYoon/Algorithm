#include <iostream>

using namespace std;

int N, M, R;
int A[101][101];
int B[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dc[] = {'N', 'S', 'W', 'E'};

int dfs(int x, int y, int d, int c) {
	if (c == 0 || 1 > x || x > N || 1 > y || y > M)
		return 0;
	int ret = (B[x][y] ? 1 : 0);
	ret += dfs(x + dx[d], y + dy[d], d, max(c, B[x][y]) - 1);
	B[x][y] = 0;
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
			B[i][j] = A[i][j];
		}
	}
	int answer = 0;
	for (int i = 0; i < R; i++) {
		int x, y;
		char d;
		cin >> x >> y >> d;
		for (int j = 0; j < 4; j++) {
			if (dc[j] == d)
				answer += dfs(x, y, j, B[x][y]);
		}
		cin >> x >> y;
		B[x][y] = A[x][y];
	}
	cout << answer << '\n';
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cout << (B[i][j] ? 'S' : 'F') << ' ';
		cout << '\n';
	}
	return 0;
}