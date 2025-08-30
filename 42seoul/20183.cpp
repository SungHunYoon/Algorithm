#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
using ll = tuple<long, long>;

long N, M, A, B, C;
vector<ll> V[100001];
long D[100001];

long dijkstra(long x) {
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	fill(D, D + N + 1, 1e18);
	pq.push({D[A] = 0, A});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (d > D[n]) continue;
		if (n == B) return D[B];
		for (auto [nD, nN] : V[n]) {
			if (x < nD) continue;
			if (d + nD > C || d + nD >= D[nN]) continue;
			pq.push({D[nN] = d + nD, nN});
		}
	}
	return D[B];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> A >> B >> C;
	long maxC = 0;
	for (int i = 1; i <= M; i++) {
		long a, b, c;
		cin >> a >> b >> c;
		V[a].push_back({c, b});
		V[b].push_back({c, a});
		maxC = max(maxC, c);
	}
	long s = 0, e = maxC + 1;
	while (s + 1 < e) {
		long mid = (s + e) / 2;
		if (dijkstra(mid) != (long)1e18) {
			e = mid;
		} else {
			s = mid;
		}
	}
	cout << (e > maxC ? -1 : e) << '\n';
	return 0;
}