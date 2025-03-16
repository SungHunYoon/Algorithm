#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M, A, B, C;
vector<ii> V[100001];
int D[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> A >> B >> C >> M;
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].push_back({c, b});
		V[b].push_back({c, a});
	}
	fill(D, D + N + 1, 1e9);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[A] = 0, A});
	pq.push({D[B] = 0, B});
	pq.push({D[C] = 0, C});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (D[n] < d) continue;
		for (auto [nD, nN] : V[n]) {
			if (D[nN] <= d + nD) continue;
			pq.push({D[nN] = d + nD, nN});
		}
	}
	cout << max_element(D + 1, D + N + 1) - D << '\n';
	return 0;
}