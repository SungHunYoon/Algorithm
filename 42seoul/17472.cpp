#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int N, M;
int A[101][101];
int B[101][101];
bool V[101][101];
int P[7];
vector<iii> E;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int x, int y, int idx) {
	queue<ii> q;
	V[x][y] = true;
	q.push({x, y});
	while (!q.empty()) {
		auto [cx, cy] = q.front(); q.pop();
		B[cx][cy] = idx;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
			if (V[nx][ny] || A[nx][ny] == 0) continue;
			V[nx][ny] = true;
			q.push({nx, ny});
		}
	}
}

void dfs(int x, int y, int idx, int dir, int cnt) {
	if (0 > x || x >= N || 0 > y || y >= M)
		return;
	if (B[x][y] != 0) {
		if (B[x][y] != idx && cnt - 1 > 1) {
			E.push_back({cnt - 1, idx, B[x][y]});
		}
		return;
	}
	dfs(x + dx[dir], y + dy[dir], idx, dir, cnt + 1);
}

int find(int idx) {
	if (P[idx] == idx)
		return idx;
	P[idx] = find(P[idx]);
	return P[idx];
}

void make_union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (a > b)
		P[a] = b;
	else
		P[b] = a;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	int idx = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!V[i][j] && A[i][j])
				bfs(i, j, idx++);
	for (int i = 1; i < idx; i++)
		P[i] = i;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (B[i][j] != 0) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					dfs(nx, ny, B[i][j], k, 1);
				}
			}
		}
	}
	sort(E.begin(), E.end());
	int cnt = 0;
	int answer = 0;
	for (auto [c, a, b] : E) {
		if (find(a) != find(b)) {
			make_union(a, b);
			cnt++;
			answer += c;
			if (cnt == idx - 2) {
				cout << answer << '\n';
				return 0;
			}
		}
	}
	cout << "-1\n";
	return 0;
}