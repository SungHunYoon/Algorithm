#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
using iii = tuple<int, int, int>;

int N, M;
int A[2001][2001];
bool V[4][2001][2001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	queue<iii> q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
			if (A[i][j] == 9) {
				for (int k = 0; k < 4; k++) {
					V[k][i][j] = true;
					q.push({k, i, j});
				}
			}
		}
	}
	while (!q.empty()) {
		auto [d, x, y] = q.front(); q.pop();
		int nx = x + dx[d];
		int ny = y + dy[d];
		int nd = d;
		if (1 > nx || nx > N || 1 > ny || ny > M) continue;
		if (A[nx][ny] == 1) {
			if (nd >= 2)
				nd ^= 1;
		}
		else if (A[nx][ny] == 2) {
			if (nd < 2)
				nd ^= 1;
		}
		else if (A[nx][ny] == 3) {
			nd ^= 3;
		} else if (A[nx][ny] == 4)
			nd ^= 2;
		if (V[nd][nx][ny]) continue;
		V[nd][nx][ny] = true;
		q.push({nd, nx, ny});
	}
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			bool flag = false;
			for (int k = 0; k < 4; k++) {
				if (V[k][i][j])
					flag = true;
			}
			if (flag) answer++;
		}
	}
	cout << answer << '\n';
	return 0;
}