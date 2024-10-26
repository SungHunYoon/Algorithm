#include <iostream>

using namespace std;

int N, M;
char A[51][51];
bool V[51][51];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool dfs(int sX, int sY, int cX, int cY, int cnt) {
	if (sX == cX && sY == cY && cnt != 0) {
		if (cnt >= 4)
			return true;
		else
			return false;
	}
	if (V[cY][cX])
		return false;
	V[cY][cX] = true;
	for (int i = 0; i < 4; i++) {
		int nX = cX + dx[i];
		int nY = cY + dy[i];
		if (0 > nX || nX >= M || 0 > nY || nY >= N) continue;
		if (A[sY][sX] != A[nY][nX]) continue;
		if (dfs(sX, sY, nX, nY, cnt + 1))
			return true;
	}
	V[cY][cX] = false;
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	bool answer = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dfs(j, i, j, i, 0)) {
				answer = true;
				break;
			}
		}
	}
	cout << (answer ? "Yes" : "No") << '\n';
	return 0;
}