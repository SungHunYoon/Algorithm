#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M, A, B, K, G;
vector<ii> V[1001];
int C[1001];
map<ii, ii> dG;
int dS[1001];

void dfs(int idx, int seq, int time) {
	if (seq >= G)
		return;
	for (auto [d, n] : V[idx]) {
		if (C[seq] != n) continue;
		int s = idx, e = n;
		if (s > e)
			swap(s, e);
		dG[{s, e}] = {time, time + d};
		dfs(n, seq + 1, time + d);
	}
}

void dijkstra(int idx) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	fill(dS, dS + N + 1, 1e9);
	pq.push({dS[idx] = 0, idx});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (dS[n] < d) continue;
		for (auto [nD, nN] : V[n]) {
			int next = d + K;
			int s = n, e = nN;
			if (s > e)
				swap(s, e);
			auto it = dG.find({s, e});
			if (it != dG.end()) {
				auto [sT, eT] = it->second;
				int nK = next + nD;
				if (sT <= next && next <= eT)
					next = eT + nD - K;
				else
					next = d + nD;
			} else {
				next = d + nD;
			}
			if (dS[nN] <= next) continue;
			pq.push({dS[nN] = next, nN});
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> A >> B >> K >> G;
	for (int i = 0; i < G; i++)
		cin >> C[i];
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].push_back({c, b});
		V[b].push_back({c, a});
	}
	dfs(C[0], 1, 0);
	dijkstra(A);
	cout << dS[B] << '\n';
	return 0;
}