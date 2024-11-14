#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;
using iiiii = tuple<int, int, int, int, int>;

int N, M, K;
int A[1001][1001];
int D[11][1001][1001];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			A[i][j] = str[j] - '0';
		}
	}
	fill(&D[0][0][0], &D[11][0][0], 1e9);
	queue<iiiii> q;
	D[0][0][0] = 1;
	q.push({0, 0, 0, 0, D[0][0][0]});
	while (!q.empty()) {
		auto [x, y, k, d, p] = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nk = k;
			int nd = d;
			int nc = 1;
			if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
			if (A[nx][ny] == 1) {
				if (nk + 1 > K) continue;
				if (nd == 1) nc++;
				else nd = !nd;
				nk++;
			} else {
				nd = !nd;
			}
			if (p + nc >= D[nk][nx][ny]) continue;
			D[nk][nx][ny] = p + nc;
			q.push({nx, ny, nk, nd, D[nk][nx][ny]});
		}
	}
	int answer = 1e9;
	for (int i = 0; i <= K; i++) {
		answer = min(answer, D[i][N - 1][M - 1]);
	}
	cout << (answer == 1e9 ? -1 : answer) << '\n';
	return 0;
}