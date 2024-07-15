#include <iostream>

using namespace std;

int N, M, D, S;
int T[51][51];
int C[51][51];
int A[51][51];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

void moveCloud() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (C[i][j] == 1) {
				int nx = (j + dx[D] * S + N * S) % N;
				int ny = (i + dy[D] * S + N * S) % N;
				if (ny == 0)
					ny = N;
				if (nx == 0)
					nx = N;
				A[ny][nx] += 1;
				C[i][j] = 0;
				T[ny][nx] = 1;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (T[i][j] == 1) {
				int cnt = 0;
				for (int k = 1; k < 8; k += 2) {
					int tx = j + dx[k];
					int ty = i + dy[k];
					if (1 > tx || tx > N || 1 > ty || ty > N) continue;
					if (A[ty][tx] > 0)
						cnt++;
				}
				A[i][j] += cnt;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i][j] >= 2 && T[i][j] == 0) {
				C[i][j] = 1;
				A[i][j] -= 2;
			}
			else if (T[i][j] == 1)
				T[i][j] = 0;
		}
	}
}

int sumMap() {
	int ret = 0;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			ret += A[i][j];
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];
	C[N][1] = C[N][2] = C[N - 1][1] = C[N - 1][2] = 1;
	for (int i = 0; i < M; i++) {
		cin >> D >> S;
		D -= 1;
		moveCloud();
	}
	cout << sumMap() << '\n';
	return 0;
}