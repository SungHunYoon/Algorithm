#include <iostream>

using namespace std;

int N, M;
int A[1001][1001];
int D[3][1001][1001];
int dx[] = {-1, 0, 0};
int dy[] = {0, -1, 1};

int dfs(int x, int y, int px, int py, int d) {
	if (D[d][x][y] != -1e9)
		return D[d][x][y];
	int ret = -1e9;
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (1 > nx || nx > N || 1 > ny || ny > M) continue;
		if (px == nx && py == ny) continue;
		ret = max(ret, dfs(nx, ny, x, y, i));
	}
	if (ret == -1e9)
		D[d][x][y] = A[x][y];
	else
		D[d][x][y] = ret + A[x][y];
	return D[d][x][y];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> A[i][j];
	fill(&D[0][0][0], &D[3][0][0], -1e9);
	int T = 0;
	for (int i = 1; i <= M; i++) {
		T += A[1][i];
		D[0][1][i] = D[1][1][i] = D[2][1][i] = T;
	}
	cout << dfs(N, M, N + 1, M + 1, 0) << '\n';
	return 0;
}