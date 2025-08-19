#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int N, M, P;
vector<ii> T[10];
int U[10];
int D[10];
char A[1001][1001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool bfs(int seq) {
	bool ret = false;
	queue<iii> q;
	for (auto [x, y] : T[seq]) {
		q.push({x, y, 0});
	}
	T[seq].clear();
	while (!q.empty()) {
		auto [x, y, c] = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nc = c + 1;
			if (1 > nx || nx > N || 1 > ny || ny > M) continue;
			if (A[nx][ny] != '.' || c >= U[seq]) continue;
			A[nx][ny] = '0' + seq;
			D[seq]++;
			T[seq].push_back({nx, ny});
			q.push({nx, ny, c + 1});
			ret = true;
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> P;
	for (int i = 1; i <= P; i++) {
		cin >> U[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
			if ('1' <= A[i][j] && A[i][j] <= '9') {
				T[A[i][j] - '0'].push_back({i, j});
				D[A[i][j] - '0']++;
			}
		}
	}
	int seq = 1, isEnd = 0;
	while (isEnd < P) {
		if (bfs(seq)) {
			isEnd = 0;
		} else {
			isEnd++;
		}
		seq = (seq + 1 > P ? 1 : seq + 1);
	}
	for (int i = 1; i <= P; i++) {
		cout << D[i] << ' ';
	}
	cout << '\n';
	return 0;
}