#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;
using iv = pair<int, vector<int>>;

int N, M, L, R, C, T;
vector<int> A;
set<vector<int>> S;
vector<ii> V[9];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T;
		A.push_back(T);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> L >> R >> C;
		V[L].push_back({C, R});
	}
	priority_queue<iv, vector<iv>, greater<iv>> pq;
	pq.push({0, A});
	int answer = 1e9;
	while (!pq.empty()) {
		auto [c, v] = pq.top(); pq.pop();
		if (is_sorted(v.begin(), v.end()))
			answer = min(answer, c);
		if (!S.insert(v).second) continue;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < V[i].size(); j++) {
				swap(v[i - 1], v[V[i][j].second - 1]);
				pq.push({c + V[i][j].first, v});
				swap(v[i - 1], v[V[i][j].second - 1]);
			}
		}
	}
	cout << (answer == 1e9 ? -1 : answer) << '\n';
	return 0;
}