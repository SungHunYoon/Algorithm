#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using iii = tuple<int, int, int>;

long H, W, L;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char C[] = {'E', 'S', 'W', 'N'};

int checkDir(char c) {
	if (c == 'E') {
		return 0;
	} else if (c == 'S') {
		return 1;
	} else if (c == 'W') {
		return 2;
	} else if (c == 'N') {
		return 3;
	}
	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> H >> W >> L) {
		if (H == 0 && W == 0 && L == 0) {
			break;
		}
		queue<iii> q;
		vector<vector<char>> A(H + 1, vector<char>(W + 1));
		vector<vector<vector<int>>> V(4, vector<vector<int>>(H + 1, vector<int>(W + 1, -1)));
		vector<iii> T;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> A[i][j];
				int dir = checkDir(A[i][j]);
				if (dir != -1) {
					V[dir][i][j] = 0;
					T.push_back({dir, i, j});
					q.push({dir, i, j});
				}
			}
		}
		int cycle = -1;
		while (!q.empty()) {
			auto [d, x, y] = q.front(); q.pop();
			if (V[d][x][y] >= L) break;
			for (int i = d; i < d + 4; i++) {
				int nd = i % 4;
				int nx = x + dx[nd];
				int ny = y + dy[nd];
				if (1 > nx || nx > H || 1 > ny || ny > W) continue;
				if (A[nx][ny] == '#') continue;
				if (V[nd][nx][ny] != -1) {
					cycle = V[nd][nx][ny];
					break;
				}
				V[nd][nx][ny] = V[d][x][y] + 1;
				T.push_back({nd, nx, ny});
				q.push({nd, nx, ny});
				break;
			}
		}
		auto [d, x, y] = (cycle == -1 ? T[L] : T[(L - T.size()) % (T.size() - cycle) + cycle]);
		cout << x << " " << y << " " << C[d] << '\n';
	}
	return 0;
}