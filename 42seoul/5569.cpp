#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 100000

int W, H;
int D[2][2][101][101];

int dfs(int p, int d, int x, int y) {
	if (1 > x || 1 > y)
		return 0;
	if (x == 1 && y == 1)
		return 1;
	if (D[p][d][x][y])
		return D[p][d][x][y];
	int ret = 0;
	if (d || !p) ret += dfs(!d, 1, x - 1, y);
	if (!d || !p) ret += dfs(d, 0, x, y - 1);
	ret %= MOD;
	return D[p][d][x][y] = ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> W >> H;
	cout << (dfs(1, 1, H, W) + dfs(1, 0, H, W)) % MOD << '\n';
	return 0;
}
