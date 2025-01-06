#include <iostream>

using namespace std;

int N;
int A[1001][1001];
int D[3][1001][1001];

int dfs(int x, int y, int t) {
	if (x > N || y > N)
		return 0;
	if (t == A[x][y] && x == N && y == N)
		return D[t][x][y] = 1;
	if (D[t][x][y])
		return D[t][x][y];
	int nt = t;
	int ret = 0;
	if (t == A[x][y]) {
		nt = (t + 1) % 3;
		ret++;
	}
	ret += max(dfs(x + 1, y, nt), dfs(x, y + 1, nt));
	return D[t][x][y] = ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];
	cout << dfs(1, 1, 0) << '\n';
	return 0;
}