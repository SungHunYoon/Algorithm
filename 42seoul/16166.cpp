#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <algorithm>

using namespace std;
using li = pair<long, int>;
using ili = tuple<int, long, int>;

int N, K, E;
vector<int> V[11];
map<li, int> D;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	priority_queue<ili, vector<ili>, greater<ili>> pq;
	for (int i = 1; i <= N; i++) {
		cin >> K;
		for (int j = 1; j <= K; j++) {
			int a;
			cin >> a;
			V[i].push_back(a);
			if (a == 0) {
				pq.push({D[{a, i}] = 0, a, i});
			}
		}
	}
	cin >> E;
	while (!pq.empty()) {
		auto [d, n, m] = pq.top(); pq.pop();
		auto it1 = D.find({n, m});
		if (it1 != D.end() && d > it1->second) continue;
		for (auto v : V[m]) {
			auto it = D.find({v, m});
			if (it == D.end()) {
				D[{v, m}] = d;
			} else if (d >= it->second) {
				continue;
			} else {
				it->second = d;
			}
			pq.push({d, v, m});
		}
		for (int i = 1; i <= N; i++) {
			if (m == i) continue;
			auto it = find(V[i].begin(), V[i].end(), n);
			if (it == V[i].end()) continue;
			auto it2 = D.find({*it, i});
			if (it2 == D.end()) {
				D[{*it, i}] = d + 1;
			} else if (d + 1 >= it2->second) {
				continue;
			} else {
				it2->second = d + 1;
			}
			pq.push({d + 1, n, i});
		}
	}
	int answer = 1e9;
	for (int i = 1; i <= N; i++) {
		auto it = D.find({E, i});
		if (it != D.end()) {
			answer = min(answer, it->second);
		}
	}
	cout << (answer == 1e9 ? -1 : answer) << '\n';
	return 0;
}