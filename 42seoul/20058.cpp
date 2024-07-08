#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int N, S, Q;
int A[64][64];
int T[64][64];
int M[64][64];
int L[64];
bool visit[64][64];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void printMap() {
	cout << "===================\n";
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++)
			cout << A[i][j] << ' ';
		cout << '\n';
	}
}

void useFireStorm(int idx) {
	int D = pow(2, L[idx]);
	int Y = 0, X = 0;
	while (Y < S) {
		for (int i = Y; i < Y + D; i++) {
			for (int j = X; j < X + D; j++) {
				T[j - X + Y][Y + D - i - 1 + X] = A[i][j];
			}
		}
		X += D;
		if (X >= S) {
			X = 0;
			Y += D;
		}
	}
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			A[i][j] = T[i][j];
}

void meltIce() {
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			M[i][j] = A[i][j];
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k];
				int ny = i + dy[k];
				if (0 > nx || nx >= S || 0 > ny || ny >= S) continue;
				if (A[ny][nx] == 0) continue;
				cnt++;
			}
			if (cnt < 3 && M[i][j])
				M[i][j]--;
		}
	}
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			A[i][j] = M[i][j];
}

int sumMap() {
	int ret = 0;

	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			ret += A[i][j];
	return ret;
}

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({y, x});
	visit[y][x] = true;
	int cnt = 0;
	while (!q.empty()) {
		auto p = q.front(); q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = p.second + dx[i];
			int ny = p.first + dy[i];

			if (0 > nx || nx >= S || 0 > ny || ny >= S) continue;
			if (visit[ny][nx] || A[ny][nx] == 0) continue;
			visit[ny][nx] = true;
			q.push({ny, nx});
		}
	}
	return cnt;
}

int maxMap() {
	int ret = 0;

	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			if (!visit[i][j] && A[i][j])
				ret = max(ret, bfs(j, i));
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> Q;
	S = pow(2, N);
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			cin >> A[i][j];
	for (int i = 0; i < Q; i++) {
		cin >> L[i];
		useFireStorm(i);
		meltIce();
		//printMap();
	}
	cout << sumMap() << '\n' << maxMap() << '\n';
	return 0;
}