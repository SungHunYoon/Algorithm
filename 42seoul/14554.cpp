#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = pair<long, long>;

int N, M, S, E, A, B, C;
vector<ll> V[100001];
long D[100001];
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> S >> E;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		V[A].push_back({B, C});
		V[B].push_back({A, C});
	}
	fill(D, D + N + 1, 1e18);
	pq.push({D[S] = 0, S});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (d > D[n]) continue;
		for (auto [nN, nD] : V[n]) {
			if (d + nD >= D[nN]) continue;
			pq.push({D[nN] = d + nD, nN});
		}
	}
	vector<ll> Q(N + 1);
	for (int i = 1; i <= N; i++) {
		Q[i] = {D[i], i};
	}
	sort(Q.begin() + 1, Q.end());
	vector<int> dp(N + 1);
	for (int i = 1; i <= N; i++) {
		auto [cD, idx] = Q[i];
		if (i == 1) {
			dp[idx] = 1;
		}
		for (auto [n, d] : V[idx]) {
			if (cD + d != D[n]) continue;
			dp[n] = (dp[n] + dp[idx]) % ((int)1e9 + 9);
		}
	}
	cout << dp[E] << '\n';
	return 0;
}