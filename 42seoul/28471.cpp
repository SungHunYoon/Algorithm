#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N;
char A[2001][2001];
bool V[2001][2001];
int dx[] = {-1, -1, -1, 0, 0, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 1};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	queue<ii> q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			if (A[i][j] == 'F') {
				V[i][j] = true;
				q.push({i, j});
			}
		}
	}
	int answer = -1;
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		answer++;
		for (int i = 0; i < 7; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 > nx || nx > N || 1 > ny || ny > N) continue;
			if (A[nx][ny] != '.' || V[nx][ny]) continue;
			V[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	cout << answer << '\n';
	return 0;
}