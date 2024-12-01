#include <iostream>

using namespace std;

int N, M;
int A[4][4];
bool V[4][4];
int answer;

void dfs(int idx, int cnt) {
	if (idx >= N * M) {
		answer = max(answer, cnt);
		return;
	}
	int y = idx / M;
	int x = idx % M;
	if (V[y][x]) {
		dfs(idx + 1, cnt);
		return;
	}
	for (int i = x; i < M; i++) {
		int nC = 0;
		bool flag = true;
		for (int j = x; j <= i; j++)
			if (V[y][j]) flag = false;
		if (!flag) break;
		for (int j = x; j <= i; j++) {
			V[y][j] = true;
			nC = nC * 10 + A[y][j];
		}
		dfs(idx + 1, cnt + nC);
		for (int j = x; j <= i; j++)
			V[y][j] = false;
	}
	for (int i = y; i < N; i++) {
		int nC = 0;
		bool flag = true;
		for (int j = y; j <= i; j++)
			if (V[j][x]) flag = false;
		if (!flag) break;
		for (int j = y; j <= i; j++) {
			V[j][x] = true;
			nC = nC * 10 + A[j][x];
		}
		dfs(idx + 1, cnt + nC);
		for (int j = y; j <= i; j++)
			V[j][x] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			A[i][j] = c - '0';
		}
	}
	dfs(0, 0);
	cout << answer << '\n';
	return 0;
}