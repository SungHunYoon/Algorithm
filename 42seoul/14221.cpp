#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M, P, Q;
vector<ii> V[5001];
int D[5001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].push_back({c, b});
		V[b].push_back({c, a});
	}
	cin >> P >> Q;
	vector<int> p(P);
	for (int i = 0; i < P; i++) {
		cin >> p[i];
	}
	fill(D, D + N + 1, 1e9);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	for (int i = 1; i <= Q; i++) {
		int q;
		cin >> q;
		pq.push({D[q] = 0, q});
	}
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (d > D[n]) continue;
		for (auto [nD, nN] : V[n]) {
			if (d + nD >= D[nN]) continue;
			pq.push({D[nN] = d + nD, nN});
		}
	}
	sort(p.begin(), p.end());
	int minD = 1e9, answer = 0;
	for (auto i : p) {
		if (minD > D[i]) {
			minD = D[i];
			answer = i;
		}
	}
	cout << answer << '\n';
	return 0;
}