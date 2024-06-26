#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using fish = tuple<int, int, int, bool>;

fish F[17];
int A[4][4];
int dx[] = {0, -1, -1, -1, 0, 1 ,1 ,1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void moveFish(fish tF[17], int tA[4][4]) {
	for (int i = 1; i <= 16; i++) {
		if (get<3>(tF[i])) {
			for (int j = 0; j < 8; j++) {
				int nx = get<0>(tF[i]) + dx[(get<2>(tF[i]) - 1 + j) % 8];
				int ny = get<1>(tF[i]) + dy[(get<2>(tF[i]) - 1 + j) % 8];
				if (0 > nx || nx >= 4 || 0 > ny || ny >= 4 || tA[ny][nx] < 0)
					continue;
				int orgF = tA[get<1>(tF[i])][get<0>(tF[i])], swapF = tA[ny][nx];
				int tmpX, tmpY;
				get<2>(tF[i]) += j;
				if (get<2>(tF[i]) > 8) {
					get<2>(tF[i]) -= 8;
				}
				tmpX = get<0>(tF[i]); tmpY = get<1>(tF[i]);
				if (tA[ny][nx] != 0) {
					get<0>(tF[i]) = get<0>(tF[tA[ny][nx]]);
					get<1>(tF[i]) = get<1>(tF[tA[ny][nx]]);
					get<0>(tF[tA[ny][nx]]) = tmpX;
					get<1>(tF[tA[ny][nx]]) = tmpY;
				} else {
					get<0>(tF[i]) = nx;
					get<1>(tF[i]) = ny;
				}
				tA[get<1>(tF[i])][get<0>(tF[i])] = orgF;
				tA[tmpY][tmpX] = swapF;
				break;
			}
		}
	}
}

int dfs(fish pF[17], int pA[4][4], int x, int y, int eat) {
	if (0 > x || x >= 4 || 0 > y || y >= 4 || !get<3>(pF[pA[y][x]]))
		return eat;

	fish tF[17];
	int tA[4][4];

	copy(pF, pF + 17, tF);
	for (int i = 0; i < 4; i++)
		copy(pA[i], pA[i] + 4, tA[i]);

	int dir = get<2>(tF[tA[y][x]]) - 1;
	int ret = 0;
	get<3>(tF[tA[y][x]]) = false;
	eat += tA[y][x];
	tA[y][x] = -1;
	moveFish(tF, tA);
	tA[y][x] = 0;
	int orgX = x, orgY = y;

	while (0 <= x && x < 4 && 0 <= y && y < 4) {
		x += dx[dir];
		y += dy[dir];
		ret = max(ret, dfs(tF, tA, x, y, eat));
	}

	get<3>(tF[tA[orgY][orgX]]) = true;

	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, dir;
			cin >> num >> dir;
			A[i][j] = num;
			F[num] = {j, i, dir, true};
		}
	}

	cout << dfs(F, A, 0, 0, 0) << '\n';

	return 0;
}