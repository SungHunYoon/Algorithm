#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
bool A[1001][1001];
int dx[] = {1, 0, 1};
int dy[] = {0, 1, 1};
int D[1001][1001];

int dfs(int x, int y) {
	if (1 > x || x > N || 1 > y || y > M || A[x][y]) {
		return 0;
	}
	if (D[x][y] != -1) {
		return D[x][y];
	}
	int ret = 0;
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (y % 2 && i > 0) {
			nx -= 1;
		}
		ret = (ret + dfs(nx, ny)) % 1000000007;
	}
	return D[x][y] = ret;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= K; i++) {
		int x, y;
		cin >> x >> y;
		A[x][y] = 1;
	}
	fill(&D[0][0], &D[1001][0], -1);
	D[N][M] = 1;
	cout << dfs(1, 1) << '\n';

	return 0;
}