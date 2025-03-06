#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int T, N, M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N >> M;
		vector<vector<int>> E(1001);
		vector<int> V(1001);
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			E[a].push_back(b);
			E[b].push_back(a);
		}
		bool flag = true;
		for (int i = 1; i <= N; i++) {
			if (V[i]) continue;
			queue<ii> q;
			V[i] = 1;
			q.push({i, 1});
			while (!q.empty()) {
				auto [n, c] = q.front(); q.pop();
				for (auto e : E[n]) {
					if (V[e] == c) {
						flag = false;
						break;
					}
					if (V[e]) continue;
					int nc = (c == 1 ? 2 : 1);
					V[e] = nc;
					q.push({e, nc});
				}
				if (!flag)
					break;
			}
			if (!flag)
				break;
		}
		cout << (flag ? "possible\n" : "impossible\n");
	}
	return 0;
}