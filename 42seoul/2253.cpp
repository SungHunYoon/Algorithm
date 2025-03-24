#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M;
int D[1001][10001];
bool T[10001];
int dx[] = {-1, 0, 1};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		T[n] = true;
	}
	queue<ii> q;
	q.push({1, 0});
	int cnt = 1;
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			auto [n, x] = q.front(); q.pop();
			for (int j = 0; j < 3; j++) {
				int nx = x + dx[j];
				if (nx <= 0) continue;
				if (n + nx > N) continue;
				if (T[n + nx] || D[nx][n + nx]) continue;
				D[nx][n + nx] = cnt;
				q.push({n + nx, nx});
			}
		}
		cnt++;
	}
	int answer = 1e9;
	for (int i = 0; i <= 1000; i++) {
		if (D[i][N] == 0) continue;
		answer = min(answer, D[i][N]);
	}
	cout << (answer == 1e9 ? -1 : answer) << '\n';
	return 0;
}