#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int M, S, X, Y, D;
int L[5][5];
map<int, int> bF[5][5];
map<int, int> F[5][5];
ii K;
int maxDirS;
vector<iii> dirS;
int dxS[] = {0, -1, 0, 1};
int dyS[] = {-1, 0, 1, 0};
int dxF[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dyF[] = {0, -1, -1, -1, 0, 1, 1, 1};

void moveFish() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (auto [d, cnt] : bF[i][j]) {
				bool flag = false;
				for (int k = 0; k < 8; k++) {
					int nd = d - k;
					if (nd < 0) nd += 8;
					int nx = j + dxF[nd];
					int ny = i + dyF[nd];
					if (1 > nx || nx > 4 || 1 > ny || ny > 4) continue;
					if (L[ny][nx] != 0) continue;
					if (ny == K.first && nx == K.second) continue;
					F[ny][nx][nd] += cnt;
					flag = true;
					break;
				}
				if (!flag) F[i][j][d] += cnt;
			}
		}
	}
}

void moveShark(vector<iii> &p, int x, int y, int cnt) {
	if (p.size() >= 3) {
		if (maxDirS < cnt) {
			maxDirS = cnt;
			dirS = p;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dxS[i];
		int ny = y + dyS[i];
		if (1 > nx || nx > 4 || 1 > ny || ny > 4) continue;
		int c = 0;
		for (auto [d, cc] : F[ny][nx]) {
			bool flag = false;
			for (auto [py, px, pf] : p) {
				if (ny == py && nx == px)
					flag = true;
			}
			if (!flag) c += cc;
		}
		p.push_back({ny, nx, c == 0 ? 0 : 1});
		moveShark(p, nx, ny, cnt + c);
		p.pop_back();
	}
}

void deleteFish() {
	for (auto [y, x, f] : dirS)
		if (f) F[y][x].clear();
	K.first = get<0>(dirS[2]);
	K.second = get<1>(dirS[2]);
}

void manageSmell() {
	for (auto [y, x, f] : dirS)
		if (f) L[y][x] = 3;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			if (L[i][j] != 0) L[i][j]--;
}

void createFish() {
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			for (auto [d, cnt] : bF[i][j])
				F[i][j][d] += cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> S;
	for (int i = 0; i < M; i++) {
		cin >> Y >> X >> D;
		D--;
		F[Y][X][D]++;
	}
	cin >> K.first >> K.second;
	while (S--) {
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				bF[i][j] = F[i][j];
				F[i][j].clear();
			}
		}
		moveFish();
		maxDirS = -1;
		dirS.clear();
		vector<iii> P;
		moveShark(P, K.second, K.first, 0);
		deleteFish();
		manageSmell();
		createFish();
	}
	int answer = 0;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			for (auto [d, cnt] : F[i][j])
				answer += cnt;
	cout << answer << '\n';
	return 0;
}

