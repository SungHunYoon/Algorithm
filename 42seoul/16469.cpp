#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int R, C;
char A[101][101];
int D[3][101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> A[i][j];
		}
	}
	fill(&D[0][0][0], &D[3][0][0], 1e9);
	queue<iii> q;
	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		D[i][x][y] = 0;
		q.push({i, x, y});
	}
	while (!q.empty()) {
		auto [d, x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 > nx || nx > R || 1 > ny || ny > C) continue;
			if (A[nx][ny] == '1' || D[d][x][y] + 1 >= D[d][nx][ny]) continue;
			D[d][nx][ny] = D[d][x][y] + 1;
			q.push({d, nx, ny});
		}
	}
	int minV = 1e9, cnt = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (D[0][i][j] == 1e9 || D[1][i][j] == 1e9 || D[2][i][j] == 1e9) continue;
			int maxV = max({D[0][i][j], D[1][i][j], D[2][i][j]});
			if (minV > maxV) {
				minV = maxV;
				cnt = 0;
			}
			if (minV == maxV) {
				cnt++;
			} 
		}
	}
	if (minV == 1e9) {
		cout << "-1\n";
	} else {
		cout << minV << '\n' << cnt << '\n';
	}
	return 0;
}