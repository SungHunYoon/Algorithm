#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
using ii = tuple<int, int>;

int N, K;
int A[101][101];
int B[101][101];
int T[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void clear(int a[101][101]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			a[i][j] = 0;
	}
}

int countCol(int n) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (A[i][n]) cnt++;
	}
	return cnt;
}

void increaseArr() {
	int mCnt = 1e9;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == 0) continue;
			mCnt = min(mCnt, A[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == mCnt)
				A[i][j]++;
		}
	}
}

void rotateArr() {
	int left = A[0][0];
	
	for (int i = 1; i < N; i++) {
		A[0][i - 1] = A[0][i];
	}
	A[0][N - 1] = 0;
	A[1][0] = left;
	
	int R = N;
	while (1) {
		clear(B);
		clear(T);
		int cut = 0;
		int maxCol = 0;
		for (int i = 0; i < N; i++, cut++) {
			int col = countCol(i);
			if (col < 2) break;
			maxCol = max(maxCol, col);
			for (int j = 0; j < col; j++) {
				B[j][i] = A[j][i];
			}
		}
		if (R - cut < maxCol) break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				T[N - j - 1][i] = B[i][j];
			}
		}
		int idx = 0;
		for (int i = cut, j = 0; i < N && A[0][i]; i++, j++, idx++) {
			B[0][j] = A[0][i];
		}
		while (T[0][0] == 0) {
			for (int i = 1; i < N; i++) {
				for (int j = 0; j < N; j++) {
					T[i - 1][j] = T[i][j];
					T[i][j] = 0;
				}
			}
		}
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {
				B[i][j] = T[i - 1][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				A[i][j] = B[i][j];
			}
		}
		R = idx;
	}
}

void calDiff() {
	queue<ii> q;
	clear(T);
	clear(B);
	B[0][0] = 1;
	q.push({0, 0});
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
			if (!A[nx][ny] || B[nx][ny]) continue;
			int d = abs(A[x][y] - A[nx][ny]) / 5;
			if (d == 0) continue;
			B[nx][ny] = 1;
			if (A[x][y] > A[nx][ny]) {
				T[x][y] -= d;
				T[nx][ny] += d;
			} else {
				T[x][y] += d;
				T[nx][ny] -= d;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] += T[i][j];
		}
	}
}

void serialize() {
	clear(B);
	int idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!A[j][i]) continue;
			B[0][idx++] = A[j][i];
		}
	}
	clear(A);
	for (int i = 0; i < N; i++) {
		A[0][i] = B[0][i];
	}
}

void divideArr() {
	int R = N;
	int P = 2;
	while (P--) {
		int pvt = R / 2;
		clear(B);
		clear(T);
		int col = countCol(0);
		for (int k = 0; k < col; k++) {
			for (int i = 0; i < pvt; i++)
				B[k][i] = A[k][i];
		}
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < pvt; j++) {
				T[col - i - 1][pvt - j - 1] = B[i][j];
			}
		}
		while (T[0][0] == 0) {
			for (int i = 1; i < N; i++) {
				for (int j = 0; j < N; j++) {
					T[i - 1][j] = T[i][j];
					T[i][j] = 0;
				}
			}
		}
		clear(B);
		int idx = 0;
		for (int k = 0; k < col; k++) {
			for (int i = pvt, j = 0; i < N; i++, j++)
				B[idx][j] = A[k][i];
			idx++;
		}
		for (int k = 0; k < col; k++) {
			for (int i = 0, j = 0; i < pvt; i++, j++)
				B[idx][j] = T[k][i];
			idx++;
		}
		clear(A);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				A[i][j] = B[i][j];
			}
		}
		R = pvt;
	}
}

int minCount() {
	int cnt = 1e9;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!A[i][j]) continue;
			cnt = min(cnt, A[i][j]);
		}
	}
	return cnt;
}

int maxCount() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cnt = max(cnt, A[i][j]);
	}
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[0][i];
	}
	int answer = 0;
	while (maxCount() - minCount() > K) {
		increaseArr();
		rotateArr();
		calDiff();
		serialize();
		divideArr();
		calDiff();
		serialize();
		answer++;
	}
	cout << answer << '\n';
	return 0;
}