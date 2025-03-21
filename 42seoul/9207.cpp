#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int T, N;
char A[6][10];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

ii dfs(vector<ii> p, int cnt) {
	ii ret = {p.size(), cnt};
	for (auto [x, y] : p) {
		for (int i = 0; i < 4; i++) {
			vector<ii> nP;
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 > nx || nx > 5 || 1 > ny || ny > 9) continue;
			if (A[nx][ny] != 'o') continue;
			int nnx = nx + dx[i];
			int nny = ny + dy[i];
			if (1 > nnx || nnx > 5 || 1 > nny || nny > 9) continue;
			if (A[nnx][nny] != '.') continue;
			for (auto [ax, ay] : p) {
				A[ax][ay] = '.';
				if (x == ax && y == ay) continue;
				else if (nx == ax && ny == ay) continue;
				nP.push_back({ax, ay});
			}
			nP.push_back({nnx, nny});
			for (auto [ax, ay] : nP)
				A[ax][ay] = 'o';
			ii tmp = dfs(nP, cnt + 1);
			for (auto [ax, ay] : nP)
				A[ax][ay] = '.';
			for (auto [ax, ay] : p)
				A[ax][ay] = 'o';
			if (ret.first > tmp.first)
				ret = tmp;
			else if (ret.first == tmp.first)
				ret.second = min(ret.second, tmp.second);
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		vector<ii> P;
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 9; j++) {
				cin >> A[i][j];
				if (A[i][j] == 'o')
					P.push_back({i, j});
			}
		}
		ii ret = dfs(P, 0);
		cout << ret.first << " " << ret.second << '\n';
	}
	return 0;
}