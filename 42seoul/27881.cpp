#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = pair<long, long>;

int N, Q;
long D[400004];
vector<ll> V[400004];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= 4 * N; i++) {
		int d;
		cin >> d;
		int curN = i, nextN = (i + 1 > 4 * N ? 1 : i + 1);
		V[curN].push_back({d, nextN});
		V[nextN].push_back({d, curN});
	}
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 3; j++) {
			int d;
			cin >> d;
			int node = i * N, station = 400000 + j;
			V[node].push_back({d, station});
			V[station].push_back({d, node});
		}
	}
	fill(D, D + 400004, 1e18);
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (int i = 1; i <= 3; i++) {
		pq.push({D[400000 + i] = 0, 400000 + i});
	}
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (d > D[n]) continue;
		for (auto [nD, nN] : V[n]) {
			if (d + nD >= D[nN]) continue;
			pq.push({D[nN] = d + nD, nN});
		}
	}
	cin >> Q;
	while (Q--) {
		int k;
		cin >> k;
		cout << D[k] << '\n';
	}

	return 0;
}