#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, K;
set<int> S;
int dx[] = {-1, 1};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	queue<ii> q;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		q.push({n, 0});
		S.insert(n);
	}
	long answer = 0, cnt = 0;
	while (!q.empty()) {
		auto [x, c] = q.front(); q.pop();
		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i];
			int nc = c + 1;
			if (!S.insert(nx).second) continue;
			cnt++;
			answer += nc;
			if (cnt >= K) {
				cout << answer << '\n';
				return 0;
			}
			q.push({nx, nc});
		}
	}
	return 0;
}