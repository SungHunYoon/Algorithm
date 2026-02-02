#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int T, N, M;

void dijkstra(vector<vector<int>> &V, vector<int> &D, int idx) {
	priority_queue<ii> pq;
	pq.push({D[idx] = 0, idx});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (d > D[n]) continue;
		for (auto next : V[n]) {
			if (D[n] + 1 >= D[next]) continue;
			pq.push({D[next] = D[n] + 1, next});
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N >> M;
		vector<vector<int>> V(N + 1);
		vector<vector<int>> rV(N + 1);
		while (M--) {
			int a, b;
			cin >> a >> b;
			V[a].push_back(b);
			rV[b].push_back(a);
		}
		vector<int> D(N + 1, 1e9);
		vector<int> rD(N + 1, 1e9);
		dijkstra(V, D, 1);
		dijkstra(rV, rD, N);

		for (int i = 1; i <= N; i++) {
			if (D[i] + rD[i] == D[N]) {
				cout << i << ' ';
			}
		}
		cout << '\n';
	}


	return 0;
}