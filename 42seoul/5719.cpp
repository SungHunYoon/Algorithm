#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

void bfs(vector<vector<ii>> &V, vector<set<int>> &T, int idx) {
	queue<int> q;
	vector<int> visit(V.size());
	visit[idx] = true;
	q.push(idx);
	while (!q.empty()) {
		int n = q.front(); q.pop();
		for (auto t : T[n]) {
			auto it = V[t].begin();
			while (it != V[t].end()) {
				if (it->second == n) {
					it = V[t].erase(it);
				} else {
					it++;
				}
			}
			if (visit[t]) continue;
			visit[t] = true;
			q.push(t);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (1) {
		int N, M, S, E;
		cin >> N >> M;
		if (N == 0 && M == 0) {
			break;
		}
		vector<vector<ii>> V(N);
		cin >> S >> E;
		for (int i = 0; i < M; i++) {
			int u, v, p;
			cin >> u >> v >> p;
			V[u].push_back({p, v});
		}
		vector<int> D(N, 1e9);
		vector<set<int>> T(N);
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		pq.push({D[S] = 0, S});
		while (!pq.empty()) {
			auto [d, n] = pq.top(); pq.pop();
			if (d > D[n]) continue;
			for (auto [nD, nN] : V[n]) {
				if (d + nD > D[nN]) continue;
				if (d + nD < D[nN]) {
					T[nN].clear();
					pq.push({D[nN] = d + nD, nN});
				}
				T[nN].insert(n);
			}
		}
		bfs(V, T, E);
		fill(D.begin(), D.end(), 1e9);
		pq.push({D[S] = 0, S});
		while (!pq.empty()) {
			auto [d, n] = pq.top(); pq.pop();
			if (d > D[n]) continue;
			for (auto [nD, nN] : V[n]) {
				if (d + nD >= D[nN]) continue;
				pq.push({D[nN] = d + nD, nN});
			}
		}
		cout << (D[E] == 1e9 ? -1 : D[E]) << '\n';
	}

	return 0;
}