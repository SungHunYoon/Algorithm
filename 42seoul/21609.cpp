#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M;
int A[21][21];
bool V[21][21];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

ii bfs(ii pos, bool f) {
	queue<ii> q;
	ii cnt;
	int org = A[pos.first][pos.second];
	q.push(pos);
	V[pos.first][pos.second] = true;
	while (!q.empty()) {
		auto [y, x] = q.front(); q.pop();
		cnt.first++;
		if (A[y][x] == 0)
			cnt.second++;
		if (f)
			A[y][x] = -2;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 > nx || nx > N || 1 > ny || ny > N) continue;
			if (V[ny][nx]) continue;
			if (A[ny][nx] < 0) continue;
			if (A[ny][nx] != org && A[ny][nx] != 0) continue;
			q.push({ny, nx});
			V[ny][nx] = true;
		}
	}
	return cnt;
}

void gravity() {
	for (int i = 1; i <= N; i++) {
		for (int j = N; j > 0; j--) {
			if (A[j][i] == -1 || A[j][i] == -2) continue;
			int b = -1;
			int k = j + 1;
			for (; k <= N; k++) {
				if (A[k][i] >= -1)
					break;
				b = k;
			}
			if (b != -1) {
				A[b][i] = A[j][i];
				A[j][i] = -2;
			}
		}
	}
}

void rotateArray() {
	int B[21][21];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			B[N - j + 1][i] = A[i][j];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			A[i][j] = B[i][j];
}

void rainbowClear() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i][j] == 0)
				V[i][j] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];
	int answer = 0;
	while (1) {
		ii blkCnt = {0, 0};
		ii blkPos = {-1, -1};
		for (int i = 1; i <= N; i++)
			fill(V[i], V[i] + N + 1, false);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!V[i][j] && A[i][j] > 0) {
					ii cnt = bfs({i, j}, false);
					if (blkCnt <= cnt) {
						blkCnt = cnt;
						blkPos = {i, j};
					}
					rainbowClear();
				}
			}
		}
		if (blkCnt.first < 2)
			break;
		for (int i = 1; i <= N; i++)
			fill(V[i], V[i] + N + 1, false);
		blkCnt = bfs(blkPos, true);
		answer += blkCnt.first * blkCnt.first;
		gravity();
		rotateArray();
		gravity();
	}
	cout << answer << '\n';
	return 0;
}
