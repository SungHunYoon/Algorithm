#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using li = pair<long, int>;

int N, M, K, A, B, C;
vector<li> V[100001];
vector<int> P;
long D[100001];

void dijkstra() {
	priority_queue<li, vector<li>, greater<li>> pq;
	for (int i = 0; i < K; i++) {
		D[P[i]] = 0;
		pq.push({0, P[i]});
	}
	while (!pq.empty()) {
		auto [dis, p] = pq.top(); pq.pop();
		if (D[p] < dis) continue;
		for (auto [nDis, nP] : V[p]) {
			if (D[nP] > dis + nDis)
				pq.push({D[nP] = dis + nDis, nP});
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		V[B].push_back({C, A});
	}
	for (int i = 0; i < K; i++) {
		cin >> A;
		P.push_back(A);
	}
	fill(D, D + N + 1, 1e18);
	dijkstra();
	int idx = -1;
	long answer = -1;
	for (int i = 1; i <= N; i++) {
		if (D[i] > answer) {
			answer = D[i];
			idx = i;
		}
	}
	cout << idx << '\n' << answer << '\n';
	return 0;
}