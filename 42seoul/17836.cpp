#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M, T;
int A[101][101];
bool visit[2][101][101];
queue<tuple<int, int, int>> q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> T;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	q.push({0, 0, 0});
	visit[0][0][0] = true;
	int answer = 0;
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			auto [g, y, x] = q.front(); q.pop();
			if (A[y][x] == 2)
				g = 1;
			if (y == N - 1 && x == M - 1) {
				cout << answer << '\n';
				return 0;
			}
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (0 > ny || ny >= N || 0 > nx || nx >= M) continue;
				if (visit[g][ny][nx]) continue;
				if (g == 0 && A[ny][nx] == 1) continue;
				visit[g][ny][nx] = true;
				q.push({g, ny, nx});
			}
		}
		if (answer >= T)
			break;
		answer++;
	}
	cout << "Fail\n";
	return 0;
}