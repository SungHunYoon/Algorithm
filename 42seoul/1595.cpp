#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int a, b, c;
vector<ii> V[10001];
int D[10001];

ii dijkstra(int idx) {
	fill(D, D + 10001, 1e9);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[idx] = 0, idx});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (d > D[n]) continue;
		for (auto [nD, nN] : V[n]) {
			if (d + nD >= D[nN]) continue;
			pq.push({D[nN] = d + nD, nN});
		}
	}
	int maxIdx = 0, maxVal = 0;
	for (int i = 1; i <= 10000; i++) {
		if (D[i] == 1e9) continue;
		if (maxVal < D[i]) {
			maxVal = D[i];
			maxIdx = i;
		}
	}
	return {maxIdx, maxVal};
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> a >> b >> c) {
		V[a].push_back({c, b});
		V[b].push_back({c, a});
	}
	auto [s, d] = dijkstra(1);
	auto [e, answer] = dijkstra(s);
	cout << answer << '\n';
	return 0;
}