#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, V, E, A, B;
int Home[101];
vector<ii> Edge[1001];
int D[2][1001];

void dijkstra(int num, int sIdx) {
	fill(D[num], D[num] + V + 1, 1e9);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[num][sIdx] = 0, sIdx});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (d > D[num][n]) continue;
		for (auto [nD, nN] : Edge[n]) {
			if (d + nD >= D[num][nN]) continue;
			pq.push({D[num][nN] = d + nD, nN});
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> V >> E >> A >> B;
	for (int i = 1; i <= N; i++)
		cin >> Home[i];
	for (int i = 0; i < E; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		Edge[a].push_back({l, b});
		Edge[b].push_back({l, a});
	}
	dijkstra(0, A);
	dijkstra(1, B);
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		int d1 = D[0][Home[i]] == 1e9 ? -1 : D[0][Home[i]];
		int d2 = D[1][Home[i]] == 1e9 ? -1 : D[1][Home[i]];
		answer += d1 + d2;
	}
	cout << answer << '\n';
	return 0;
}