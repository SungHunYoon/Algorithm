#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
using li = tuple<long, int>;

int N, M;
vector<li> V[100001];
long D[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back({i, b});
		V[b].push_back({i, a});
	}
	fill(D, D + N + 1, 1e18);
	priority_queue<li, vector<li>, greater<li>> pq;
	pq.push({D[1] = 0, 1});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (d > D[n]) continue;
		for (auto [nS, nN] : V[n]) {
			long wait = (nS - d % M + M) % M;
			if (d + wait + 1 >= D[nN]) continue;
			pq.push({D[nN] = d + wait + 1, nN});
		}
	}
	cout << D[N] << '\n';
	return 0;
}