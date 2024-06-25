#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int A[1001][1001];
bool visit[1001][1001];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int idx, int x, int y) {
	int ret = 0;
	queue<pair<int, int>> q;
	visit[y][x] = true;
	q.push({y, x});
	while (!q.empty()) {
		auto p = q.front(); q.pop();
		A[p.first][p.second] = idx;
		ret++;
		for (int i = 0; i < 4; i++) {
			int nx = p.second + dx[i];
			int ny = p.first + dy[i];
			if (0 <= nx && nx < M && 0 <= ny && ny < N) {
				if (A[ny][nx] == 1 && !visit[ny][nx]) {
					visit[ny][nx] = true;
					q.push({ny, nx});
				}
			}
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];

	map<int, int> m;
	int idx = 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] == 1) {
				m[idx] = bfs(idx, j, i);
				idx++;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] == 0) {
				set<int> s;
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (0 <= nx && nx < M && 0 <= ny && ny < N) {
						if (s.insert(A[ny][nx]).second)
							cnt += m[A[ny][nx]];
					}
				}
				answer = max(answer, cnt + 1);
			}
		}
	}
	cout << answer << '\n';

	return 0;
}