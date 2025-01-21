#include <iostream>

using namespace std;

int N, M;
int A[25][25];
int dx[] = {0, -1, -1};
int dy[] = {-1, 0, -1};

int dfs(int idx, int c) {
	int x = idx / M;
	int y = idx % M;
	if (c >= 15)
		return 0;
	if (idx >= N * M)
		return 1;
	int ret = 0, cnt = 0;
	ret = dfs(idx + 1, 0);
	A[x][y] = 1;
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
		if (A[nx][ny]) cnt |= (1 << i);
	}
	ret += dfs(idx + 1, cnt | (1 << 3));
	A[x][y] = 0;
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	cout << dfs(0, 0) << '\n';

	return 0;
}