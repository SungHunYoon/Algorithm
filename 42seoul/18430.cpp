#include <iostream>

using namespace std;

int N, M;
int A[5][5];
bool V[5][5];
int dx[] = {1, 1, 0, 1, 1, 1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int answer;

int checkVisit(int idx, int dir, int flag) {
	int ret = 0;
	int x = idx / M;
	int y = idx % M;
	for (int i = dir * 2; i < dir * 2 + 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (flag == 0) {
			if (0 > nx || nx >= N || 0 > ny || ny >= M || V[nx][ny])
				return ret;
		}
		else if (flag == 1) {
			V[nx][ny] = true;
			ret += i % 2 ? A[nx][ny] : A[nx][ny] * 2;
		}
		else if (flag == 2) {
			V[nx][ny] = false;
			ret += i % 2 ? A[nx][ny] : A[nx][ny] * 2;
		}
	}
	if (flag == 0) ret = 1;
	return ret;
}

void dfs(int idx, int cnt) {
	if (idx >= N * M) {
		answer = max(answer, cnt);
		return;
	}
	dfs(idx + 1, cnt);
	int x = idx / M;
	int y = idx % M;
	if (V[x][y]) return;
	V[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (!checkVisit(idx, i, 0)) continue;
		cnt += checkVisit(idx, i, 1) + A[x][y];
		dfs(idx + 1, cnt);
		cnt -= checkVisit(idx, i, 2) + A[x][y];
	}
	V[x][y] = false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	dfs(0, 0);
	cout << answer << '\n';
	return 0;
}