#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M;
int A[22][22];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
pair<int, int> C[2];
bool visit[21][21][21][21];
queue<tuple<int, int, int, int>> q;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	int idx = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char c;
			cin >> c;
			if (c == '#')
				A[i][j] = 1;
			if (c == 'o')
				C[idx++] = {i, j};
		}
	}
	int answer = 0;
	q.push({C[0].first, C[0].second, C[1].first, C[1].second});
	visit[C[0].first][C[0].second][C[1].first][C[1].second] = true;
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++)
		{
			auto [y1, x1, y2, x2] = q.front(); q.pop();

			if ((x1 <= 0 || x1 > M || y1 <= 0 || y1 > N) &&
				(x2 <= 0 || x2 > M || y2 <= 0 || y2 > N))
				continue;
			if ((x1 <= 0 || x1 > M || y1 <= 0 || y1 > N) ||
				(x2 <= 0 || x2 > M || y2 <= 0 || y2 > N)) {
				cout << answer << '\n';
				return 0;
			}

			for (int j = 0; j < 4; j++) {
				int nx1 = x1 + dx[j];
				int ny1 = y1 + dy[j];
				int nx2 = x2 + dx[j];
				int ny2 = y2 + dy[j];
				if (A[ny1][nx1] == 1) {
					nx1 = x1;
					ny1 = y1;
				}
				if (A[ny2][nx2] == 1) {
					nx2 = x2;
					ny2 = y2;
				}
				if (visit[ny1][nx1][ny2][nx2]) continue;
				visit[ny1][nx1][ny2][nx2] = true;
				q.push({ny1, nx1, ny2, nx2});
			}
		}
		if (answer >= 10)
			break;
		answer++;
	}
	cout << "-1\n";
	return 0;
}