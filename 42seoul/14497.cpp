#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
pair<int, int> P;
pair<int, int> O;
bool A[301][301];
bool visit[301][301];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool flag;

bool dfs(int x, int y) {
	if (1 > x || x > M || 1 > y || y > N)
		return false;
	visit[y][x] = true;
	if (A[y][x]) {
		if (y == O.first && x == O.second)
			flag = true;
		A[y][x] = false;
		return true;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!visit[ny][nx])
			dfs(nx, ny);
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	cin >> P.first >> P.second >> O.first >> O.second;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char c;
			cin >> c;
			if (c == '1' || c == '#')
				A[i][j] = true;
		}
	}
	int cnt = 0;
	while (!flag) {
		cnt++;
		for (int i = 1; i <= N; i++)
			fill(visit[i] + 1, visit[i] + 1 + M, false);
		dfs(P.second, P.first);
	}
	cout << cnt << '\n';
	return 0;
}