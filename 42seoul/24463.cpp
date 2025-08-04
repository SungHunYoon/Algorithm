#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M;
char A[2002][2002], B[2002][2002];
ii D[2002][2002];
int X[2], Y[2];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	int idx = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
			B[i][j] = A[i][j];
			if (B[i][j] == '.') {
				B[i][j] = '@';
				if (i == 1 || j == 1 || i == N || j == M) {
					X[idx] = i;
					Y[idx] = j;
					idx++;
				}
			}
		}
	}
	fill(&D[0][0], &D[2002][0], make_pair(-1, -1));
	queue<ii> q;
	D[X[0]][Y[0]].first = 0;
	q.push({X[0], Y[0]});
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		if (X[1] == x && Y[1] == y) break;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 > nx || nx > N || 1 > ny || ny > M) continue;
			if (A[nx][ny] == '+' || D[nx][ny].first >= 0) continue;
			D[nx][ny] = {x, y};
			q.push({nx, ny});
		}
	}
	int tX = X[1], tY = Y[1];
	while (D[tX][tY].first != 0) {
		B[tX][tY] = '.';
		auto [x, y] = D[tX][tY];
		tX = x;
		tY = y;
	}
	B[X[0]][Y[0]] = '.';
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << B[i][j];
		}
		cout << '\n';
	}
	return 0;
}