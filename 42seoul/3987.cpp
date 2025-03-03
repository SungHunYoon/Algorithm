#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int N, M, PR, PC;
string A[501];
char cd[] = {'U', 'R', 'D', 'L'};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool V[4][501][501];

int bfs(int x, int y, int d) {
	queue<iii> q;
	q.push({x, y, d});
	V[d][x][y] = true;
	while (!q.empty()) {
		auto [x, y, d] = q.front(); q.pop();
		int nx = x + dx[d];
		int ny = y + dy[d];
		int nd = d;
		if (1 > nx || nx > N || 1 > ny || ny > M) continue;
		if (A[nx][ny - 1] == 'C') continue;
		if (A[nx][ny - 1] == '/')
			nd ^= 1;
		if (A[nx][ny - 1] == '\\')
			nd ^= 3;
		if (V[nd][nx][ny])
			return -1;
		V[nd][nx][ny] = true;
		q.push({nx, ny, nd});
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 0; k < 4; k++) {
				if (V[k][i][j])
					cnt++;
			}
		}
	}
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	cin >> PR >> PC;
	char dir;
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		fill(&V[0][0][0], &V[4][0][0], false);
		int cnt = bfs(PR, PC, i);
		if (cnt > answer || cnt == -1) {
			answer = cnt;
			dir = cd[i];
		}
		if (answer == -1)
			break;
	} 
	cout << dir << '\n';
	if (answer == -1)
		cout << "Voyager\n";
	else
		cout << answer << '\n';
	return 0;
}