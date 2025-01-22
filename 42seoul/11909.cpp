#include <iostream>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;
using iii = tuple<int, int, int>;

int N;
int A[2223][2223];
int D[2223][2223];
int dx[] = {1, 0};
int dy[] = {0, 1};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			D[i][j] = 1e9;
		}
	}
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({D[1][1] = 0, 1, 1});
	while (!pq.empty()) {
		auto [c, x, y] = pq.top(); pq.pop();
		if (D[x][y] < c) continue;
		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nc = 0;
			if (nx > N || ny > N) continue;
			if (A[x][y] <= A[nx][ny]) nc = A[nx][ny] - A[x][y] + 1;
			if (D[x][y] + nc >= D[nx][ny]) continue;
			pq.push({D[nx][ny] = D[x][y] + nc, nx, ny});
		}
	}
	cout << D[N][N] << '\n';
	return 0;
}