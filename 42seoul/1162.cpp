#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<long, int, int>;

int N, M, K, A, B, C;
vector<ii> V[10001];
long D[21][10001];

void dijkstra(int idx) {
	for (int i = 0; i <= K; i++)
		D[i][idx] = 0;
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({0, idx, 0});
	while (!pq.empty()) {
		auto [dis, p, k] = pq.top(); pq.pop();
		if (D[k][p] < dis)
			continue;
		for (auto [nDis, nP] : V[p]) {
			if (D[k][nP] > nDis + dis)
				pq.push({(D[k][nP] = nDis + dis), nP, k});
		}
		if (k + 1 <= K) {
			for (auto [nDis, nP] : V[p]) {
				if (D[k + 1][nP] > dis)
					pq.push({(D[k + 1][nP] = dis), nP, k + 1});
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		V[A].push_back({C, B});
		V[B].push_back({C, A});
	}
	for (int i = 0; i <= K; i++)
		fill(D[i] + 1, D[i] + N + 1, 1e11);
	dijkstra(1);
	long answer = 1e11;
	for (int i = 0; i <= K; i++)
		answer = min(answer, D[i][N]);
	cout << answer << '\n';
	return 0;
}