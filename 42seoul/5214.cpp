#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, K, M, X;
set<int> T[1001];
vector<int> V[100001];
int D[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> X;
			T[i].insert(X);
			V[X].push_back(i);
		}
	}
	fill(D, D + N + 1, 1e9);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	D[1] = 1;
	for (int i = 0; i < V[1].size(); i++)
		pq.push({1, V[1][i]});
	while (!pq.empty()) {
		auto [d, t] = pq.top(); pq.pop();
		for (auto idx : T[t]) {
			if (d + 1 < D[idx]) {
				D[idx] = d + 1;
				for (int i = 0; i < V[idx].size(); i++) {
					pq.push({d + 1, V[idx][i]});
				}
			}
		}
		T[t].clear();
	}
	cout << (D[N] == 1e9 ? -1 : D[N]) << '\n';
	return 0;
}