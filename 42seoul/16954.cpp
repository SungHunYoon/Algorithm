#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

char A[9][9];
bool V[9][9][9];
int dx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

void moveBlock() {
	for (int i = 8; i > 0; i--)
		for (int j = 1; j <= 8; j++)
			A[i][j] = A[i - 1][j];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			cin >> A[i][j];
	queue<iii> q;
	q.push({8, 1, 0});
	V[0][8][1] = true;
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			auto [y, x, v] = q.front(); q.pop();
			if (y == 1 && x == 8) {
				cout << "1\n";
				return 0;
			}
			if (A[y][x] == '#') continue;
			if (v + 1 < 9) v++;
			for (int j = 0; j < 9; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (1 > nx || nx > 8 || 1 > ny || ny > 8) continue;
				if (A[ny][nx] == '#') continue;
				if (V[v][ny][nx]) continue;
				q.push({ny, nx, v});
				V[v][ny][nx] = true;
			}
		}
		moveBlock();
	}
	cout << "0\n";
	return 0;
}