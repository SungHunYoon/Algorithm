#include <iostream>

using namespace std;

int N, D;
int A[11][11];

int remainColumn(int idx) {
	bool T[10] = { 0 };
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (A[idx][i] == -1) continue;
		T[A[idx][i]] = true;
	}
	for (int i = 0; i < D; i++) {
		if (!T[i]) ret++;
	}
	return ret;
}

int remainRow(int idx) {
	bool T[10] = { 0 };
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (A[i][idx] == -1) continue;
		T[A[i][idx]] = true;
	}
	for (int i = 0; i < D; i++) {
		if (!T[i]) ret++;
	}
	return ret;
}

bool checkDuplication(int r, int c, int v, bool dir) {
	for (int i = 0; i < N; i++) {
		if (dir) {
			if (A[i][c] == v) {
				return false;
			}
		} else {
			if (A[r][i] == v) {
				return false;
			}
		}
	}
	return true;
}

bool dfs(int idx) {
	int r = idx / N;
	int c = idx % N;
	if (idx % N == 0 && r > 0 && remainColumn(r - 1)) {
		return false;
	}
	if ((idx / N == N || (idx / N == N - 1 && c > 0)) && remainRow((c - 1 + N) % N)) {
		return false;
	}
	if (idx >= N * N) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << A[i][j] << ' ';
			}
			cout << '\n';
		}
		return true;
	}
	int rColumn = remainColumn(r);
	int rRow = remainRow(c);
	if (rColumn > N - c) return false;
	if (rRow > N - r) return false;

	for (int i = 0; i < D; i++) {
		bool flag = true;
		if (rColumn == N - c) {
			flag &= checkDuplication(r, c, i, false);
		}
		if (rRow == N - r) {
			flag &= checkDuplication(r, c, i, true);
		}
		if (!flag) continue;
		A[r][c] = i;
		if (dfs(idx + 1)) {
			return true;
		}
		A[r][c] = -1;
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = -1;
		}
	}
	dfs(0);
	return 0;
}