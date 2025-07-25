#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, S, P;
vector<int> V[328001];
int D[328001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> S >> P;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	fill(D, D + N + 1, 1e9);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[P] = 0, P});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (d > D[n]) continue;
		for (auto nN : V[n]) {
			if (d + 1 >= D[nN]) continue;
			pq.push({D[nN] = d + 1, nN});
		}
	}
	sort(D + 1, D + S + 1);
	cout << N - 1 - (D[1] + D[2]) << '\n'; 
	return 0;
}