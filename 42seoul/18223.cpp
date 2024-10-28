#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int V, E, P, A, B, C;
vector<ii> X[5001];
int D[2][5001];

void dijkstra(int idx, int dest) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	D[dest][idx] = 0;
	pq.push({0, idx});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (d > D[dest][n]) continue;
		for (auto [nD, nN] : X[n]) {
			if (d + nD < D[dest][nN])
				pq.push({D[dest][nN] = d + nD, nN});
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> V >> E >> P;
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		X[A].push_back({C, B});
		X[B].push_back({C, A});
	}
	for (int i = 0; i < 2; i++)
		fill(D[i], D[i] + V + 1, 1e9);
	dijkstra(1, 0);
	dijkstra(P, 1);
	if (D[0][V] >= D[0][P] + D[1][V])
		cout << "SAVE HIM\n";
	else
		cout << "GOOD BYE\n";
	return 0;
}