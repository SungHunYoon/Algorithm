#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M, K;
long D[101][101];
map<ii, vector<ii>> m;
int dx[] = {1, 0};
int dy[] = {0, 1};

long dfs(int x, int y) {
	if (D[x][y])
		return D[x][y];
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 > nx || nx > N || 0 > ny || ny > M) continue;
		auto it = m.find({x, y});
		if (it != m.end() &&
			find(it->second.begin(), it->second.end(), pair(nx, ny)) != it->second.end())
			continue;
		D[x][y] += dfs(nx, ny);
	}
	return D[x][y];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		m[{a, b}].push_back({c, d});
		m[{c, d}].push_back({a, b});
	}
	D[N][M] = 1;
	cout << dfs(0, 0) << '\n';
	return 0;
}