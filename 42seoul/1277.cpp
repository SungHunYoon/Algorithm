#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;
using di = pair<double, int>;

int N, W;
double M;
ii A[1001];
vector<di> V[1001];
double D[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> W >> M;
	for (int i = 1; i <= N; i++) {
		cin >> A[i].first >> A[i].second;
		for (int j = 1; j < i; j++) {
			double d = sqrt((pow(abs(A[i].first - A[j].first), 2) + pow(abs(A[i].second - A[j].second), 2)));
			if (d > M) continue;
			V[i].push_back({d, j});
			V[j].push_back({d, i});
		}
	}
	for (int i = 0; i < W; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back({0, b});
		V[b].push_back({0, a});
	}
	priority_queue<di, vector<di>, greater<di>> pq;
	fill(D, D + N + 1, 1e9);
	pq.push({D[1] = 0, 1});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (d > D[n]) continue;
		for (auto [nd, nN] : V[n]) {
			if (D[n] + nd >= D[nN]) continue;
			pq.push({D[nN] = D[n] + nd, nN});
		}
	}
	cout << (int)(D[N] * 1000) << '\n';
	return 0;
}