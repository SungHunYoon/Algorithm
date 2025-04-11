#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int R, C;
ii S;
vector<ii> D;
string A[101];
int V[101][101];
string M;
int dx[] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

bool moveArduino(char c) {
	int dir = (c - '0') - 1;
	int nx = S.first + dx[dir];
	int ny = S.second + dy[dir];
	if (A[nx][ny] == 'R')
		return false;
	A[S.first][S.second] = '.';
	S = {nx, ny};
	A[nx][ny] = 'I';
	return true;
}

bool moveCrazyArduino() {
	for (auto &[x, y] : D) {
		int minD = 1e9;
		int mx, my;
		V[x][y]--;
		A[x][y] = '.';
		for (int i = 0; i < 9; i++) {
			if (i == 4) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];
			int d = abs(S.first - nx) + abs(S.second - ny);
			if (minD <= d) continue;
			minD = d;
			mx = nx;
			my = ny;
		}
		x = mx;
		y = my;
		if (A[x][y] == 'I')
			return false;
		V[x][y]++;
	}
	return true;
}

void checkCrazyArduino() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (V[i][j] > 1) {
				for (auto it = D.begin(); it != D.end();) {
					if (it->first == i && it->second == j)
						it = D.erase(it);
					else
						it++;
				}
				V[i][j] = 0;
			}
			else if (V[i][j] == 1)
				A[i][j] = 'R';

		}
	}
}

void printMap() {
	for (int i = 0; i < R; i++) {
		cout << A[i] << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> A[i];
		for (int j = 0; j < A[i].size(); j++) {
			if (A[i][j] == 'I') {
				S = {i, j};
			}
			if (A[i][j] == 'R') {
				D.push_back({i, j});
				V[i][j]++;
			}
		}
	}
	cin >> M;
	for (int i = 0; i < M.size(); i++) {
		if (!moveArduino(M[i])) {
			cout << "kraj " << i + 1 << '\n';
			return 0;
		}
		if (!moveCrazyArduino()) {
			cout << "kraj " << i + 1 << '\n';
			return 0;
		}
		checkCrazyArduino();
	}
	printMap();
	return 0;
}