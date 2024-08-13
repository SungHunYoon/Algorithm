#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, A, B, C;
vector<pair<int, int>> V[50001];
int D[50001];

void dijkstra(int idx) {
	D[idx] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, idx});
	while (!pq.empty()) {
		auto [dis, p] = pq.top(); pq.pop();
		if (D[p] < dis)
			continue;
		for (int i = 0; i < V[p].size(); i++) {
			int nP = V[p][i].second;
			int nDis = D[p] + V[p][i].first;
			if (nDis < D[nP]) {
				D[nP] = nDis;
				pq.push({nDis, nP});
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		V[A].push_back({C, B});
		V[B].push_back({C, A});
	}
	fill(D, D + N + 1, 1e9);
	dijkstra(1);
	cout << D[N] << '\n';
	return 0;
}