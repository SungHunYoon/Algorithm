#include <iostream>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;
using ii = tuple<int, int>;

int N, C;
char E;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (1) {
		cin >> N;
		if (N == 0)
			break;
		vector<ii> R(N + 1);
		vector<vector<int>> V(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> E >> C;
			R[i] = {E, C};
			while (1) {
				int next;
				cin >> next;
				if (next == 0)
					break;
				V[i].push_back(next);
			}
		}
		queue<ii> q;
		vector<int> D(N + 1, -1);
		q.push({D[1] = 0, 1});
		while (!q.empty()) {
			auto [cost, current] = q.front(); q.pop();
			auto [rType, rCost] = R[current];
			if (cost < D[current]) continue;
			if (rType == 'L') {
				if (cost < rCost)
					cost = rCost;
			}
			else if (rType == 'T') {
				if (cost < rCost)
					continue;
				cost -= rCost;
			}
			D[current] = cost;
			for (auto next : V[current]) {
				if (cost <= D[next]) continue;
				q.push({cost, next});
			}
		}
		cout << (D[N] == -1 ? "No" : "Yes") << '\n';
	}
	return 0;
}