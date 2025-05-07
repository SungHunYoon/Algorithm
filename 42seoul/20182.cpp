#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M, A, B, C;
vector<ii> V[100001];
int D[100001];

int dijkstra(int idx, int standard) {
	int ret = 0;
	fill(D, D + N + 1, 1e9);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[idx] = 0, idx});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (D[n] > d) continue;
		for (auto [nD, nN] : V[n]) {
			if (nD > standard) continue;
			if (d + nD > C || d + nD >= D[nN]) continue;
			ret = max(ret, nD);
			pq.push({D[nN] = d + nD, nN});
		}
	}
	return (D[B] == 1e9 ? 1e9 : ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> A >> B >> C;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].push_back({c, b});
		V[b].push_back({c, a});
	}
	int answer = 1e9;
	for (int i = 20; i > 0; i--) {
		answer = min(answer, dijkstra(A, i));
	}
	cout << (answer == 1e9 ? -1 : answer) << '\n';
	return 0;
}