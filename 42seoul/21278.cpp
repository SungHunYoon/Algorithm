#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M;
vector<ii> V[101];
int D[101];

void dijkstra(int idx1, int idx2) {
	fill(D, D + N + 1, 1e9);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[idx1] = 0, idx1});
	pq.push({D[idx2] = 0, idx2});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (d > D[n]) continue;
		for (auto [nD, nN] : V[n]) {
			if (nD + D[n] < D[nN]) {
				pq.push({D[nN] = nD + D[n], nN});
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back({1, b});
		V[b].push_back({1, a});
	}
	ii p = {-1, -1};
	int minValue = 1e9;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			dijkstra(i, j);
			int value = 0;
			for (int k = 1; k <= N; k++) {
				value += D[k] * 2;
			}
			if (minValue > value) {
				p = {i, j};
				minValue = value;
			}
		}
	}
	cout << p.first << " " << p.second << " " << minValue << '\n';
	return 0;
}