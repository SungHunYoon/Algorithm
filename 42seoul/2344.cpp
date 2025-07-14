#include <iostream>
#include <map>
#include <tuple>

using namespace std;
using iii = tuple<int, int, int>;

int N, M;
int A[1001][1001];
map<iii, int> B;
int V[4001];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int changeDir(int d) {
	if (d == 0) {
		return 3;
	} else if (d == 1) {
		return 2;
	} else if (d == 2) {
		return 1;
	} else {
		return 0;
	}
}

void ray(int x, int y, int d, int n) {
	if (1 > x || x > N || 1 > y || y > M) {
		int px = x + dx[d ^ 1];
		int py = y + dy[d ^ 1];
		int idx = B[{px, py, d ^ 1}];
		V[idx] = n;
		V[n] = idx;
		return;
	}
	if (A[x][y] == 1) {
		d = changeDir(d);
	}
	int nx = x + dx[d];
	int ny = y + dy[d];
	ray(nx, ny, d, n);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		B.insert({{i, 1, 1}, i});
	}
	for (int i = 1; i <= M; i++) {
		B.insert({{N, i, 2}, N + i});
	}
	for (int i = N; i >= 1; i--) {
		B.insert({{i, M, 0}, N + M + (N - i + 1)});
	}
	for (int i = M; i >= 1; i--) {
		B.insert({{1, i, 3}, 2 * N + M + (M - i + 1)});
	}
	for (int i = 1; i <= N; i++) {
		int idx = B[{i, 1, 1}];
		if (V[idx]) continue;
		ray(i, 1, 1, idx);
	}
	for (int i = 1; i <= M; i++) {
		int idx = B[{N, i, 2}];
		if (V[idx]) continue;
		ray(N, i, 2, idx);
	}
	for (int i = N; i >= 1; i--) {
		int idx = B[{i, M, 0}];
		if (V[idx]) continue;
		ray(i, M, 0, idx);
	}
	for (int i = M; i >= 1; i--) {
		int idx = B[{1, i, 3}];
		if (V[idx]) continue;
		ray(1, i, 3, idx);
	}
	for (int i = 1; i <= 2 * N + 2 * M; i++) {
		cout << V[i] << ' ';
	}
	cout << '\n';
	return 0;
}