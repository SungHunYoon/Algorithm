#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, A, B, X, Y, Z;
vector<ii> V[100001];
ii T[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> A >> B;
	for (int i = 0; i < N - 1; i++) {
		cin >> X >> Y >> Z;
		V[X].push_back({Y, Z});
		V[Y].push_back({X, Z});
	}
	queue<ii> q;
	int answer = 0;
	q.push({A, 0});
	while (!q.empty()) {
		auto [p, d] = q.front(); q.pop();
		if (p == B) {
			answer = d;
			break;
		}
		for (auto [nP, nD] : V[p]) {
			if (T[nP].first != 0 && T[nP].second != 0) continue;
			T[nP] = {p, nD};
			q.push({nP, d + nD});
		}
	}
	int idx = B;
	int maxD = 0;
	while (idx != A) {
		maxD = max(maxD, T[idx].second);
		idx = T[idx].first;
	}
	cout << answer - maxD << '\n';
	return 0;
}