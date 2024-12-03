#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
using ii = pair<long, int>;

int N, M;
int A[100001];
vector<ii> V[100001];
long D[100001];

void dijkstra(int idx) {
	fill(D, D + N, 1e14);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	D[idx] = 0;
	pq.push({0, idx});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (d > D[n]) continue;
		for (auto [nD, nN] : V[n]) {
			if (A[n] == 1 || D[n] + nD >= D[nN]) continue;
			pq.push({D[nN] = D[n] + nD, nN});
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < M; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		V[a].push_back({t, b});
		V[b].push_back({t, a});
	}
	dijkstra(0);
	if (D[N - 1] == 1e14)
		cout << "-1\n";
	else
		cout << D[N - 1] << '\n';
	return 0;
}