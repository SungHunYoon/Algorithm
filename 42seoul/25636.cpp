#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using ll = tuple<long, long>;
using lll = tuple<long, long, long>;

ll dijkstra(vector<int> &A, vector<vector<ll>> &V, int S, int E) {
	priority_queue<lll, vector<lll>, greater<lll>> pq;
	vector<long> D(V.size(), 1e18);
	vector<long> W(V.size());
	pq.push({D[S] = 0, W[S] = A[S], S});
	while (!pq.empty()) {
		auto [d, w, n] = pq.top(); pq.pop();
		if (d > D[n] || w < W[n]) continue;
		for (auto [nD, nN] : V[n]) {
			if (d + nD > D[nN]) continue;
			if (d + nD == D[nN] && w + A[nN] <= W[nN]) continue;
			pq.push({D[nN] = d + nD, W[nN] = w + A[nN], nN});
		}
	}
	return {D[E], W[E]};
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, S, E;
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	cin >> M;
	vector<vector<ll>> V(N + 1, vector<ll>());
	for (int i = 1; i <= M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		V[u].push_back({w, v});
		V[v].push_back({w, u});
	}
	cin >> S >> E;
	auto [d, w] = dijkstra(A, V, S, E);
	if (d == 1e18) {
		cout << "-1\n";
	} else {
		cout << d << " " << w << '\n';
	}
	return 0;
}