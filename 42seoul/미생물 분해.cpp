#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, Q;
int A[15][15];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void printArr() {
	cout << "======================\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << A[i][j];
		}
		cout << '\n';
	}
}

set<int> fillSquare(int r1, int c1, int r2, int c2, int idx) {
	set<int> S;
	for (int i = r1 - 1; i >= r2; i--) {
		for (int j = c1; j <= c2 - 1; j++) {
			S.insert(A[i][j]);
			A[i][j] = idx;
		}
	}
	return S;
}

int bfs(int x, int y, vector<vector<int>> &V) {
	queue<ii> q;
	int T = A[x][y];
	int cnt = 0;

	V[x][y] = true;
	q.push({x, y});
	while (!q.empty()) {
		auto [cx, cy] = q.front(); q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
			if (V[nx][ny] || A[nx][ny] != T) continue;
			V[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	return cnt;
}

void checkSquare(set<int> &S) {
	for (auto s : S) {
		int cnt = 0;
		int bCnt = 0;
		
		vector<vector<int>> V(N + 1, vector<int>(N + 1));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (A[i][j] == s) {
					if (cnt == 0)
						bCnt = bfs(i, j, V);
					cnt++;
				}
			}
		}
		if (bCnt != cnt) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (A[i][j] == s) {
						A[i][j] = 0;
					}
				}
			}
		}
	}
}

int checkSize() {
	int maxCnt = 0, idx = 0;
	vector<vector<int>> V(N + 1, vector<int>(N + 1));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!V[i][j] && A[i][j]) {
				int cnt = bfs(i, j, V);
				if (maxCnt < cnt) {
					maxCnt = cnt;
					idx = A[i][j];
				} else if (maxCnt == cnt && idx > A[i][j]) {
					idx = A[i][j];
				}
			}
		}
	}
	return idx;
}

bool checkPlace(int cx, int cy, vector<vector<int>> &B, set<ii> &S) {
	for (auto [x, y] : S) {
		int nx = cx + x;
		int ny = cy + y;
		if (0 > nx || nx >= N || 0 > ny || ny >= N)
			return false;
		if (B[nx][ny])
			return false;
	}
	return true;
}

void setPlace(int cx, int cy, vector<vector<int>> &B, set<ii> &S, int idx) {
	for (auto [x, y] : S) {
		int nx = cx + x;
		int ny = cy + y;
		B[nx][ny] = idx;
	}
}

void moveSquare() {
	vector<vector<int>> B(N + 1, vector<int>(N + 1));
	int idx;
	while ((idx = checkSize())) {
		set<ii> S;
		int sx = -1, sy = -1;
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				if (idx == A[i][j]) {
					if (sx == -1 && sy == -1) {
						sx = i;
						sy = j;
						S.insert({0, 0});
					} else {
						S.insert({i - sx, j - sy});
					}
					A[i][j] = 0;
				}
			}
		}
		bool flag = false;
		for (int j = 0; j < N; j++) {
			for (int i = N - 1; i >= 0; i--) {
				if (checkPlace(i, j, B, S)) {
					setPlace(i, j, B, S, idx);
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			A[i][j] = B[i][j];
	}
}

int calculate() {
	int C[51] = { 0, };
	vector<vector<int>> V(N + 1, vector<int>(N + 1));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!V[i][j] && A[i][j]) {
				C[A[i][j]] = bfs(i, j, V);
			}
		}
	}
	set<ii> S;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!A[i][j]) continue;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
				if (A[nx][ny] == 0 || A[nx][ny] == A[i][j]) continue;
				int s = A[nx][ny], e = A[i][j];
				if (s > e)
					swap(s, e);
				S.insert({s, e});
			}
		}
	}
	int ret = 0;
	for (auto [s, e] : S)
		ret += C[s] * C[e];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> Q;
	for (int i = 1; i <= Q; i++) {
		int r1, c1, r2, c2;
		cin >> c1 >> r1 >> c2 >> r2;
		set<int> S = fillSquare(N - r1, c1, N - r2, c2, i);
		checkSquare(S);
		moveSquare();
		cout << calculate() << '\n';
	}
	return 0;
}