#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int R, C;
char A[1001][1001];
bool V[1001][1001];
int X, Y;
string S;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y) {
	queue<ii> q;
	V[x][y] = true;
	q.push({x, y});
	while (!q.empty()) {
		auto [cx, cy] = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (1 > nx || nx > R || 1 > ny || ny > C) continue;
			if (A[x][y] != A[nx][ny]) continue;
			if (V[nx][ny]) continue;
			V[nx][ny] = true;
			q.push({nx, ny});
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> A[i][j];
	cin >> X >> Y >> S;
	for (char c : S) {
		if (c == 'W')
			bfs(X, Y);
		else if (c == 'L')
			Y -= 1;
		else if (c == 'U')
			X -= 1;
		else if (c == 'R')
			Y += 1;
		else if (c == 'D')
			X += 1;
	}
	V[X][Y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = X + dx[i];
		int ny = Y + dy[i];
		if (1 > nx || nx > R || 1 > ny || ny > C) continue;
		V[nx][ny] = true;
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++)
			cout << (V[i][j] ? '.' : '#');
		cout << '\n';
	}
	return 0;
}